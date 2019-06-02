//������������ word1 �� word2��������� word1 ת���� word2 ��ʹ�õ����ٲ����� ��
//����Զ�һ�����ʽ����������ֲ�����
//����һ���ַ�
//ɾ��һ���ַ�
//�滻һ���ַ�
//ʾ�� 1:
//����: word1 = "horse", word2 = "ros"
//	��� : 3
//	���� :
//	horse->rorse(�� 'h' �滻Ϊ 'r')
//	rorse->rose(ɾ�� 'r')
//	rose->ros(ɾ�� 'e')
//	ʾ�� 2 :
//	���� : word1 = "intention", word2 = "execution"
//	��� : 5
//	���� :
//	intention->inention(ɾ�� 't')
//	inention->enention(�� 'i' �滻Ϊ 'e')
//	enention->exention(�� 'n' �滻Ϊ 'x')
//	exention->exection(�� 'n' �滻Ϊ 'c')
//	exection->execution(���� 'u')

ԭ����ͣ����ǰ�word1.size() + 1��Ϊ��ά����ĺ����곤�ȣ� word2.size() + 1��Ϊ��ά����������곤�ȣ��ٰѺ������0������size��д���ٰ��������0������size��д
��˼��������һ��c Ҫ��� cta cta����Ϊ��0�� 1�� 2����Ҫɾ��2�������������ĸ����Ҫ�����κθı����ȡ���Ϸ����ݣ�������һ���ַ���Ҫ�Ĳ��裬��һ�β���Ҫ�ı䣬
�������ͬ����Ҫ�������ϣ��϶���1������С��

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