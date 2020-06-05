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
    linkedList* insert(string data){
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
        return head;
    }
    bool find(){
        if(this->head==NULL){
            return false;
        }
        else{
            return true;
        }
    }
    void delete(string data){       //not working
        linkedList *temp=head;
        linkedList *prev;
        while(temp!=NULL){
            prev=temp;
            if(temp->str==data){
                break;
            }
            temp=temp->next;
        }
        if (temp==head){
            head=head->next;
        }
        else{
            prev->next=temp->next;
            temp->next=NULL;
            free(temp);
        }
        return 0;
    }
};
class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    std::vector<linkedList> hash;
    vector<string> elems;

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
            hash[hash_func(query.s)].insert(query.s);
        }
        else if(query.type=="find"){
            if(hash[hash_func(query.s)].find()){
                cout<<"yes";
            }
            else{
                cout<<"no";
            }
        }
        else if (query.type=="del"){
            hash[hash_func(query.s)].delete(query.s);
        }
       /* if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
                if (hash_func(elems[i]) == query.ind)
                    std::cout << elems[i] << " ";
            std::cout << "\n";
        } else {
            vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems.end());
            else if (query.type == "add") {
                if (it == elems.end())
                    elems.push_back(query.s);
            } else if (query.type == "del") {
                if (it != elems.end())
                    elems.erase(it);
            }
        }*/
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
