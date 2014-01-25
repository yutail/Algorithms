vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int>> result;
    
    if (num.size() == 1) {
        result.push_back(num);
        return result;
    }
    
    int a = num.back();
    num.pop_back();
    
    vector<vector<int>> temp = permute(num);
    
    vector<vector<int>>::iterator it;
    vector<int>::iterator it2;
    
    for (it=temp.begin(); it!=temp.end(); it++) {
        for (int i=0; i<=(*it).size(); i++) {
            result.push_back(*it);
            it2 = result.back().begin();
            result.back().insert(it2+i, a);
        }
    }
    return result;
}