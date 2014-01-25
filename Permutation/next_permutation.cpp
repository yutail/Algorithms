//Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
//Find the largest index l such that a[k] < a[l].
//Swap the value of a[k] with that of a[l].
//Reverse the sequence from a[k + 1] up to and including the final element a[n].

void nextPermutation(vector<int> &num) {
    int index = -1;
    for (int k=0; k <num.size()-1; k++) {
        if (num[k] < num[k+1]) {
            index = k;
        }
    }
    if (index == -1) {
        reverse(num.begin(), num.end());
        return;
    }
    
    int l;
    for (int i=index+1; i < num.size(); i++) {
        if (num[i] > num[index]) {
            l = i;
        }
    }
    
    int temp = num[index];
    num[index] = num[l];
    num[l] = temp;
    
    reverse(num.begin()+index+1, num.end());
}