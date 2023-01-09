#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int match = 0; // lottos와 win_nums 배열 사이 일치하는 원소의 개수를 담을 변수
    int zero_cnt = 0;

    for (int j = 0; j < win_nums.size(); j++) {
        for (int i = 0; i < lottos.size(); i++) {
            if (lottos[i] == win_nums[j])
                match++;
        }
    }
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0)
            zero_cnt++;
    }
    // match에는 당첨번호와 일치한 번호의 개수가 담긴다.
    // zero_cnt + match(maximum: 6)이 최대 당첨 번호 개수이다.

    int best, worst;
    int best_match = match + zero_cnt;


    switch (match) {
    case 2:
        worst = 5;
        break;
    case 3:
        worst = 4;
        break;
    case 4:
        worst = 3;
        break;
    case 5:
        worst = 2;
        break;
    case 6:
        worst = 1;
        break;
    default:
        worst = 6;
        break;
    }

    switch (best_match) {
    case 2:
        best = 5;
        break;
    case 3:
        best = 4;
        break;
    case 4:
        best = 3;
        break;
    case 5:
        best = 2;
        break;
    case 6:
        best = 1;
        break;
    default:
        best = 6;
        break;
    }
    
    answer.push_back(best);
    answer.push_back(worst);
    return answer;
}

int main() {
    vector<int> lottos;
    lottos.push_back(44);
    lottos.push_back(1);
    lottos.push_back(0);
    lottos.push_back(0);
    lottos.push_back(31);
    lottos.push_back(25);

    vector<int> win_nums;
    win_nums.push_back(6);
    win_nums.push_back(1);
    win_nums.push_back(19);
    win_nums.push_back(45);
    win_nums.push_back(31);
    win_nums.push_back(10);

    //int a = solution
    vector<int> a = solution(lottos, win_nums);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}