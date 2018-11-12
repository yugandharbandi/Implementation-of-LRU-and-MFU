#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main_memory_size=20;


vector<int>employee_page_table(1000);
vector<int>department_page_table(100);
vector<int>project_page_table(500);
vector<int>main_memory(main_memory_size);
string reference_pattern="";
long long page_fault_count=0;




class MFUCache{
    // store keys of cache 
    list<int> dq; 
  
    // store references of key in cache 
    unordered_map<int, list<int>::iterator> ma; 
    int csize; //maximum capacity of cache 
  
public: 
    MFUCache(int); 
    void refer(int); 
}; 
  
MFUCache::MFUCache(int n){ 
    csize = n;
}
 
// Refers key x with in the LRU cache 
void MFUCache::refer(int x){ 
    // not present in cache 

    if (ma.find(x) == ma.end()) { 
        // cache is full 
            page_fault_count++; 
        if (dq.size() == csize){ 
            //delete least recently used element 
            int last = dq.front();
            if(last>1000){
                department_page_table[last-1000-1]=0;
            }
            else{
                employee_page_table[last-1]=0;
            }
            dq.pop_front();
            ma.erase(last);
        }
    } 
  
    // present in cache 
    else
        dq.erase(ma[x]); 
  
    // update reference 
    dq.push_front(x); 
    ma[x] = dq.begin(); 
}



class LRUCache{
    // store keys of cache 
    list<int> dq; 
  
    // store references of key in cache 
    unordered_map<int, list<int>::iterator> ma; 
    int csize; //maximum capacity of cache 
  
public: 
    LRUCache(int); 
    void refer(int); 
}; 
  
LRUCache::LRUCache(int n){ 
    csize = n;
}
 
/* Refers key x with in the LRU cache */
void LRUCache::refer(int x){ 
    // not present in cache 
    if (ma.find(x) == ma.end()) { 
    	page_fault_count++;
        // cache is full 
        if (dq.size() == csize){ 
            //delete least recently used element 
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    } 
  
    // present in cache 
    else
        dq.erase(ma[x]); 
  
    // update reference 
    dq.push_front(x); 
    ma[x] = dq.begin(); 
}


MFUCache lru_available_buffers(main_memory_size);
// MFUCache mfu_available_buffers(main_memory_size);

void get_page_number_for_employee(int i){
    // if(!employee_page_table[i-1]){ //if the block is not in main memory, serve the page fault
        lru_available_buffers.refer(i);
        // employee_page_table[i-1]=1;
    // }
}

void get_page_number_for_department(int j){
    // if(!department_page_table[j-1]){ //if the block is not in main memory, serve the page fault
        lru_available_buffers.refer(j+1000);
        // department_page_table[j-1]=1;
    // }
}

void implement_query1(){
    for(int i=1;i<=1000;i++){    //as there are 10000 blocks of employee, iterate all of them!
        get_page_number_for_employee(i);
        for(int j=1;j<=100;j++){
            get_page_number_for_department(j);
            for(int k=0;k<10;k++){
       			get_page_number_for_employee(i);
                for(int l=0;l<10;l++){
			        get_page_number_for_department(j);
                }
            }
        }
    }
}

int main(){
    implement_query1();
    cout<<page_fault_count<<endl;
}