#include <bits/stdc++.h>

using namespace std;
list<int> *adj;
vector<string> split_string(string);

vector<int> Utils(int v, vector<int> &visited, vector<int> &vect) {
    visited[v] = 1;
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i){
        if(visited[*i]==0){
            vect.push_back(*i);
            Utils(*i,visited, vect);
        }
    }
    return vect;
}

// Complete the journeyToMoon function below.
int journeyToMoon(int n, vector<vector<int>> astronaut) {
      adj = new list<int>[n+1];
      vector<vector<int> > country;
      long long result = 1;
      vector<int> v(n,0);
    for(int i=0;i<astronaut.size();i++){
      adj[astronaut[i][0]].push_back(astronaut[i][1]);
      adj[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    for(int i=0;i<n;i++){
        if(v[i] == 0) {
            vector<int>vect;
            vect = Utils(i,v,vect);
            country.push_back(vect);
        }
    }
    int sum = 0;
    for(int i=0;i<country.size();i++){
        if(country[i].size()){
            sum+=(country[i].size()+1);
            result= result * (country[i].size()+1);
            cout<<result<<" "<<country[i].size()+1<<endl;
        }     
    }
    if(sum == n) {
        return result;
    }
    int left = n - sum;
    cout<<left<<"this "<<endl;
    return (result * left) + ((left * (left-1))/2);;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
