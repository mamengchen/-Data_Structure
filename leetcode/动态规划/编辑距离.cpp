//给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
//你可以对一个单词进行如下三种操作：
//插入一个字符
//删除一个字符
//替换一个字符
//示例 1:
//输入: word1 = "horse", word2 = "ros"
//	输出 : 3
//	解释 :
//	horse->rorse(将 'h' 替换为 'r')
//	rorse->rose(删除 'r')
//	rose->ros(删除 'e')
//	示例 2 :
//	输入 : word1 = "intention", word2 = "execution"
//	输出 : 5
//	解释 :
//	intention->inention(删除 't')
//	inention->enention(将 'i' 替换为 'e')
//	enention->exention(将 'n' 替换为 'x')
//	exention->exection(将 'n' 替换为 'c')
//	exection->execution(插入 'u')

原理解释：我们把word1.size() + 1作为二维数组的横坐标长度， word2.size() + 1作为二维数组的纵坐标长度，再把横坐标从0到长度size填写，再把纵坐标从0到长度size填写
意思：假如你一个c 要变成 cta cta依次为：0， 1， 2；需要删除2步，如果两个字母不需要进行任何改变则就取左上方数据，这是上一个字符需要的步骤，这一次不需要改变，
如果不相同则需要在左，左上，上都加1，找最小。

class Solution {
public:
	int minDistance(string word1, string word2) {
		int col = word1.size();
		int row = word2.size();
		std::vector<std::vector<int>> my_vec(col + 1, std::vector<int>(row + 1, 0));
		for (int i = 0; i <= col; i++) my_vec[i][0] = i;
		for (int i = 0; i <= row; i++) my_vec[0][i] = i;

		for (int i = 1; i <= col; i++)
		{
			for (int j = 1; j <= row; j++)
			{
				if (word1[i - 1] == word2[j - 1])
				{
					my_vec[i][j] = my_vec[i - 1][j - 1];
				}
				else
				{
					my_vec[i][j] = min(my_vec[i - 1][j] + 1, min(my_vec[i - 1][j - 1] + 1, my_vec[i][j - 1] + 1));
				}
			}
		}
		return my_vec[col][row];
	}
};