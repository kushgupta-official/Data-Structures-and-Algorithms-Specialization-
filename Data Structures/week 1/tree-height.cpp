# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node *root=NULL;
node* newNode(int key){
  struct node* p=new node;
  p->data=key;
  p->left=NULL;
  p->right=NULL;
  return p;
}

void createNode(std::vector<int> arr, int i, node *created[], node **root) 
{ 
    if (created[i] != NULL) 
        return; 
  
    created[i] = newNode(i); 
  
    if (arr[i] == -1) 
    { 
        *root = created[i]; 
        return; 
    } 
  
    if (created[arr[i]] == NULL) 
        createNode(arr, arr[i], created, root); 
  
    node *p = created[arr[i]]; 
  
    if (p->left == NULL) 
        p->left = created[i]; 
    else 
        p->right = created[i]; 
} 

node* create_tree(std::vector<int> arr,size_t n){
  node *created[n]; 
    for (int i=0; i<n; i++) 
        created[i] = NULL; 
  
    node *root = NULL; 
    for (size_t i=0; i<n; i++) 
        createNode(arr, i, created, &root); 
  
    return root; 
}
void inorder(node* p){
  if(p){
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
  }
}
long long max_height(node *p){
  if(p==NULL){
    return 0;
  }
  else{
    return(1+max(max_height(p->left),max_height(p->right)));
  }
}

int main(void){
  size_t n=0;
  cin>>n;
  std::vector<int> arr(n);
  for (size_t i=0;i<n;i++){
    cin>>arr[i];
  }
  root=create_tree(arr,n);
  inorder(root);
  cout<<endl;
  cout<<max_height(root);
}