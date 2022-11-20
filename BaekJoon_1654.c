/*
   �����̰� ������ ������ �ִ� K ���� ����,
   ( �� ��, K ���� ������ ���̴� �Է¹޴´�. )

   �����̴� �����̰� ���� ���̰� �������� K���� ������ ���� ������ N���� ����⸦ ���Ѵ�.

   ���� �� �ִ� �ִ� ������ ���̸� ���϶�.

   ��, N���� ������ ������ �ѿ����� K���� ������ ���� ���̸� ���϶�.


   4 11
   802
   743
   457
   539

   => 200
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_K 10001
long long have[MAX_K];
int K, N;      // ������ �ִ� ������ ������, ������ �̿��Ͽ� ���� ������ ����

long long low, high, mid;      // �̺� Ž�� ���� �Ű�����
long long result;            // ��°�(����)

int main() {
    //printf("������ �ִ� ������, �ش� �������� �̿��Ͽ� �� ���� �����ϰ� �����Ű��� : ");
    long long max_have = 0;

    // ������ �ִ� ������ ���� K �Է¹ޱ�
    scanf("%d %d", &K, &N);

    //printf("������ ���̸� ���� �Է����ּ���! ");


    for (int i = 0; i < K; i++) {
        scanf("%lld", &have[i]);

        // K���� ���� �� ���� ū ���� max_have�� ����
        if (max_have < have[i])
            max_have = have[i];
    }

    low = 1; // K�� 1 �̻��̶�� ����
    high = max_have;

    result = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        // ������ �ڸ��� ���� ������ ���� ���� (N���� ��)
        int cnt = 0;

        // �߰������� ��� �������� ���� ���� cnt�� �����ش�.
        for (int i = 0; i < K; i++) {
            cnt += have[i] / mid;
        }

        // �� ���� or ����
        // ���� ���� Ȥ�� �� ũ�� �ڸ� �� ���� ��
        if (cnt >= N) {
            low = mid + 1;

            // ������ �� ���� ū ���̸� ��������� ���� ����
            // mid ���� result�� �־���
            // while �� ������ ������ result�� N���� ������ ������Ű�� ���� ū ���� �� �ִ�.
            if (result < mid)
                result = mid;
        }
        else {   // cnt < N ���� ���� ������ ��
            high = mid - 1;
        }
    }

    printf("%lld\n", result);
    return 0;
}