#include<iostream>
#include<vector>
#include<memory>

// 点结构体
struct Point {
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
};

// 四叉树节点类
class QuadTreeNode
{
private:
    // 这个节点范围
    struct Boundary{
        double x,y,width,height;
    };
    Boundary _boundary;
    // 这个节点范围有多少个点
    std::vector<Point> _points;
    bool _subdivided;
    int _depth;
    static const int CapaCity = 4;  // 每个节点可容纳的最大点数

    // 细分四叉树 子范围
    std::vector<std::unique_ptr<QuadTreeNode>> _children;

    // 检查点是否在当前节点的边界内
    bool contains(Point point) {
        return (_boundary.x <= point.x && point.x < _boundary.x + _boundary.width && 
        _boundary.y <= point.y && point.y < _boundary.y + _boundary.height);
    }

    // 检查查询范围是否与当前节点的边界相交
    bool intersects(double x, double y, double width, double height) {
        return !(_boundary.x + _boundary.width <= x || _boundary.x >= x + width || _boundary.y + _boundary.height <= y || _boundary.y >= y + height);
    }


    // 细分当前节点
    void subdivide() {
        double x = _boundary.x;
        double y = _boundary.y;
        double w = _boundary.width / 2.0;
        double h = _boundary.height / 2.0;

        // 动态分配子节点
        _children.push_back(std::make_unique<QuadTreeNode>(x, y, w, h, _depth + 1));
        _children.push_back(std::make_unique<QuadTreeNode>(x + w, y, w, h, _depth + 1));
        _children.push_back(std::make_unique<QuadTreeNode>(x, y + h, w, h, _depth + 1));
        _children.push_back(std::make_unique<QuadTreeNode>(x + w, y + h, w, h, _depth + 1));

        // 将当前节点的点重新分配到子节点
        for (const auto& point : _points) {
            for (auto& child : _children) {
                if (child->insert(point)) {
                    break;
                }
            }
        }

        _points.clear();   // 清空当前节点的点
        _subdivided = true;
    }
    
public:
    QuadTreeNode(double x, double y, double width, double height, int depth);
    ~QuadTreeNode();
    // 插入操作
    bool insert(Point point);
    // 删除操作
    bool remove(Point point);
    // 查询范围内的点
    std::vector<Point> queryRange(double x, double y, double width, double height);
};

QuadTreeNode::QuadTreeNode(double x, double y, double width, double height, int depth = 0)
{
    _boundary = QuadTreeNode::Boundary {x, y, width, height};
    _depth = depth;
    _subdivided = false;
}

QuadTreeNode::~QuadTreeNode() {}

// 插入节点
bool QuadTreeNode::insert(Point point) {
    // 检查点是否在当前节点的范围内
    if (!contains(point)) {
        return false;
    }

    // 如果当前节点是叶子节点且没有达到分割阈值，则直接存储点
    if (!_subdivided && _points.size() < CapaCity) {
        _points.push_back(point);
        return true;
    }

    // 如果当前节点不是叶子节点或者点数量达到阈值，则细分节点
    if (!_subdivided) {
        subdivide();
    }

    // 递归将点插入到子节点
    for (auto& child: _children) {
        if (child->insert(point)) {
            return true;
        }
    }

    return false;
}

// 删除节点
bool QuadTreeNode::remove(Point point) {
    // 检查点是否在当前节点的范围内
    if (!contains(point)){
        return false;
    }
    
    // 尝试在当前节点中删除点
    for (auto it = _points.begin(); it != _points.end(); ++it) {
        if (it->x == point.x && it->y == point.y){
            _points.erase(it);
            return true;
        }
    }

    // 如果已细分，递归删除子节点中的点
    if (_subdivided) {
        for (auto& child : _children) {
            if (child->remove(point)) {
                return true;
            }
        }
    }
    return false;
}

// 查询范围内的点
std::vector<Point> QuadTreeNode::queryRange(double x, double y, double width, double height) {
    std::vector<Point> result;

    // 检查查询范围是否与当前节点的边界相交
    if (!intersects(x, y, width, height)) {
        return result;
    }

    // 检查当前节点的点是否在查询范围内
    for (const auto& point : _points) {
        if (x <= point.x && point.x < x + width && y <= point.y && point.y < y + height) {
            result.push_back(point);
        }
    }

    // 递归查询子节点
    if (_subdivided) {
        for (const auto& child : _children) {
            auto childResults = child->queryRange(x, y, width, height);
            result.insert(result.end(), childResults.begin(), childResults.end());
        }
    }

    return result;
}

int main() {
    QuadTreeNode quadtree(0, 0, 100, 100);
    quadtree.insert(Point(10,10));
    quadtree.insert(Point(20,20));
    quadtree.insert(Point(50,50));
    quadtree.insert(Point(70,70));

    // 查询范围内的点
    std::vector<Point> pointsInRange = quadtree.queryRange(0,0,30,30);
    std::cout << "Points within range:" << std::endl;
    for (const auto& point : pointsInRange) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    //删除点
    quadtree.remove(Point(20, 20));
    pointsInRange = quadtree.queryRange(0,0,30,30);
    std::cout << "\nPoints within range after removal:" << std::endl;
    for (const auto& point : pointsInRange) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }
    return 0;
}

