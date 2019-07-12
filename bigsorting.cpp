#include <bits/stdc++.h>

using namespace std;

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {    
    for(int i=0;i<unsorted.size();i++){
        for(int j=0;j<unsorted.size()-1;j++){
            if (unsorted[j].length() > unsorted[j+1].length()) {
                string temp = unsorted[j];
                unsorted[j] = unsorted[j+1];
                unsorted[j+1] = temp;
            }
            if(unsorted[j].length() == unsorted[j+1].length()){
              string temp = "3084193741082937";
              string temp1 = "3084193741082937";
                long long k = stol(temp);
                long long l = stol(temp1);
                if(k>l){
                    unsorted[j+1] = to_string(l);
                    unsorted[j] = to_string(k);
                }
            }
        }
    }

    return unsorted;
}

int main()
{
     ifstream input;
    input.open("input.txt");
    int n;
    input >> n;

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        if(i==0){
          continue;
        }
        getline(input, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
      cout<<result[i]<<endl;
    }
    return 0;
}
