#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
    string type;
    string s;
    size_t ind;
};
class linkedList{
    string str;
    linkedList *next;
    linkedList *head;
public:
    linkedList(){
        this->head=NULL;
    }
    void insert(string data){
        if (this->head==NULL){
            this->head=new linkedList();
            this->head->str=data;
            this->head->next=NULL;
        }
        else{
            linkedList *temp=new linkedList();
            temp->str=data;
            temp->next=head;
            this->head=temp;
        }
    }
    bool find(string s){
        if(this->head==NULL){
            return false;
        }
        else{
            linkedList *temp=head;
            while(temp!=NULL){
                if (temp->str==s){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }
    }
    void del(string data){       
        linkedList *temp=head;
        linkedList *prev;
        if(head==NULL){
            return;
        }
        while(temp!=NULL){
            if(temp->str==data){
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        if (temp==head){
            head=head->next;
            temp->next=NULL;
            free(temp);
        }
        else{
            prev->next=temp->next;
            temp->next=NULL;
            free(temp);
        }
    }

    void display(){
        if (this->head!=NULL){
            linkedList *temp=head;
            while(temp!=NULL){
                cout<<temp->str<<" ";
                temp=temp->next;
            }
        }
        cout<<endl;
    }
};
class QueryProcessor {
    int bucket_count;
    std::vector<linkedList> hash;

    size_t hash_func(const string& s) const {       //function for hashing strings
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) 
    {
        hash.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if(query.type=="add"){
            if(hash[hash_func(query.s)].find(query.s)==0){
                hash[hash_func(query.s)].insert(query.s);
            }
        }
        else if(query.type=="find"){
            if(hash[hash_func(query.s)].find(query.s)){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
        }
        else if (query.type=="del"){
            if(hash[hash_func(query.s)].find(query.s)==1){
                hash[hash_func(query.s)].del(query.s);
            }
        }
        else if (query.type=="check"){
            hash[query.ind].display();
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
