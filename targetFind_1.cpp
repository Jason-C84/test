#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
*��һ����ά�����У�ÿ��һά����ĳ�����ͬ����
*ÿһ�ж����մ����ҵ�����˳������
*ÿһ�ж����մ��ϵ��µ�����˳������
*�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/
bool Find(int target, vector<vector<int> > array) {
    /* �����ǵ�һ�ֽⷨ
    vector <vector<int> >::iterator iterVV = array.begin();
    while(iterVV != array.end()){
        vector<int>::iterator iterV = (*iterVV).begin();
        while(iterV != (*iterVV).end()){
            if(*iterV == target){
                return true;
            }
            iterV++;
        }
        iterVV++;
    }
    return false;
    */
    /*�����ǵڶ��ֽⷨ*/
    int row = array.size();
    int col = array[0].size();

    if(row == 0 && col == 0){
        return false;
    }

    int j = 0;
    int i = 0;

    if(col > 0){
        j = col - 1;
    }

    while(j >= 0 && j < col && i < row && i >= 0){
        if(array[i][j] == target){
            return true;
        }else if(array[i][j] > target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

int main(int argc, char *argv[]){
    int target = 0;
    vector<vector<int> >  v(4, vector<int>(4));
    v[0] = {1,2,8,9};
    v[1] = {2,4,9,12};
    v[2] = {4,7,10,13};
    v[3] = {6,8,11,15};
    target = 7;

    bool result = Find(target, v);
    string res = result>0?"true":"false";

    cout << res << endl;

    return 0;
}
