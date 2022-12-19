/*
	N��, M���� ���ڿ��� ���� ���Ͽ�

	�� ���ܿ� ��� ���ϴ� ���ڿ��� ������ �� ���ڿ��� ���ĵ� ���·� ����ϱ�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>	// �� 500000���� �� �� �ִ� N,M���� ���ڿ��� �������� ���ڿ��μ� ǥ���ϱ� ����
#include <algorithm>	// ��� ���͸� �����Ͽ� ǥ���ϱ� ����

using namespace std;
int N, M;

int main() {
	scanf("%d %d", &N, &M);
	vector<string> result;	// �������� sort(result.begin(), result.end()); �� �̿��� ���ĵ� ���·� ������� ����
	vector<string> non_heard_name;
	non_heard_name.resize(N);	// ��Ÿ�ӿ��� �����ϱ� ���� �̸� ����¡���ֱ�
	
	char temp[21]; // ���⿡ �־���ٰ� non~ �������� ���Ϳ� �־��� ���� �߰��ܰ� ���� ����


	// �� �� ���� �ο� ���
	for (int i = 0; i < N; i++) {
		scanf("%s", temp);
		non_heard_name[i] = temp;
	}
	sort(non_heard_name.begin(), non_heard_name.end()); // ����Ž���� �Ϸ��� �ش� Ž������ ���ĵ� ���¿��� �Ѵ�.
	// �ð� ���⵵�� ���� ����Ž��
	// binary_search(a, b, c);  --> a : ���� / b: �� / c: ã���� �ϴ� ��

	// �� �� ���� �ο� ����� �Է¹����� ���ÿ� non_heard_name ��ܿ� �����ϴ� �̸����� ���غ���.
	for (int i = 0; i < M; i++) {
		scanf("%s", temp);
		if (binary_search(non_heard_name.begin(), non_heard_name.end(), temp)) {	// non_heard_name ��ܿ� �����Ѵٸ�.
			result.push_back(temp); // result �����迭�� ����־��.
		}
	}
	sort(result.begin(), result.end()); // ���ĵ� ���·� ������ֱ� ���� sort
	//cout << result.size() << '\n';
	printf("%d\n", result.size());

	for (int i = 0; i < result.size(); i++) {
		//cout << result[i] << '\n';
		printf("%s\n", result[i].c_str());
	}

}