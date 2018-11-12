#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main_memory_size=2500;

vector<int>employee_page_table(1000);
vector<int>department_page_table(100);
vector<int>project_page_table(500);
vector<int>main_memory(main_memory_size);
string reference_pattern="";
long long lru_page_fault_count=0;
long long mfu_page_fault_count=0;

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
            mfu_page_fault_count++; 
        if (dq.size() == csize){ 
            //delete least recently used element 
            int last = dq.front();
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
    	lru_page_fault_count++;
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


LRUCache lru_available_buffers_1(main_memory_size);
LRUCache lru_available_buffers_2(main_memory_size);
LRUCache lru_available_buffers_3(main_memory_size);
LRUCache lru_available_buffers_4(main_memory_size);

MFUCache mfu_available_buffers_1(main_memory_size);
MFUCache mfu_available_buffers_2(main_memory_size);
MFUCache mfu_available_buffers_3(main_memory_size);
MFUCache mfu_available_buffers_4(main_memory_size);
// MFUCache mfu_available_buffers(main_memory_size);

void get_page_number_for_employee(int i,int num){
	if(num==1){
    	lru_available_buffers_1.refer(i);
    	mfu_available_buffers_1.refer(i);
	}
	if(num==2){
    	lru_available_buffers_2.refer(i);
    	mfu_available_buffers_2.refer(i);
	}
	if(num==3){
    	lru_available_buffers_3.refer(i);
    	mfu_available_buffers_3.refer(i);
	}
	if(num==4){
    	lru_available_buffers_4.refer(i);
    	mfu_available_buffers_4.refer(i);
	}
}

void get_page_number_for_department(int j,int num){
	if(num==1){
    	lru_available_buffers_1.refer(j+1000);
    	mfu_available_buffers_1.refer(j+1000);
	}
	if(num==2){
    	lru_available_buffers_2.refer(j+1000);
    	mfu_available_buffers_2.refer(j+1000);
	}
	if(num==3){
    	lru_available_buffers_3.refer(j+1000);
    	mfu_available_buffers_3.refer(j+1000);
	}
	if(num==4){
    	lru_available_buffers_4.refer(j+1000);
    	mfu_available_buffers_4.refer(j+1000);
	}
}

void get_page_number_for_project(int j,int num){
	if(num==1){
    	lru_available_buffers_1.refer(j+1100);
    	mfu_available_buffers_1.refer(j+1100);
	}
	if(num==2){
    	lru_available_buffers_2.refer(j+1100);
    	mfu_available_buffers_2.refer(j+1100);
	}
	if(num==3){
    	lru_available_buffers_3.refer(j+1100);
    	mfu_available_buffers_3.refer(j+1100);
	}
	if(num==4){
    	lru_available_buffers_4.refer(j+1100);
    	mfu_available_buffers_4.refer(j+1100);
	}
}

void implement_query1(){
    for(int i=1;i<=1000;i++){   
        get_page_number_for_employee(i,1);
        for(int j=1;j<=100;j++){
            get_page_number_for_department(j,1);
            for(int k=0;k<10;k++){
       			get_page_number_for_employee(i,1);
                for(int l=0;l<10;l++){
			        get_page_number_for_department(j,1);
                }
            }
        }
    }
}

void implement_query2(){
    for(int i=1;i<=100;i++){    
        get_page_number_for_department(i,2);
        for(int j=1;j<=1000;j++){
            get_page_number_for_employee(j,2);
            for(int k=0;k<10;k++){
       			get_page_number_for_department(i,2);
                for(int l=0;l<10;l++){
			        get_page_number_for_employee(j,2);
                }
            }
        }
    }
}

void implement_query3(){
    for(int i=1;i<=500;i++){    
        get_page_number_for_project(i,3);
        for(int j=1;j<=100;j++){
            get_page_number_for_department(j,3);
            for(int k=0;k<10;k++){
       			get_page_number_for_project(i,3);
                for(int l=0;l<10;l++){
			        get_page_number_for_department(j,3);
                }
            }
        }
    }
}

void implement_query4(){
    for(int i=1;i<=100;i++){    
        get_page_number_for_department(i,4);
        for(int j=1;j<=500;j++){
            get_page_number_for_project(j,4);
            for(int k=0;k<10;k++){
       			get_page_number_for_department(i,4);
                for(int l=0;l<10;l++){
			        get_page_number_for_project(j,4);
                }
            }
        }
    }
}


int main(){
    implement_query1();
    cout<<lru_page_fault_count<<" "<<mfu_page_fault_count<<endl;
    lru_page_fault_count=0;
    mfu_page_fault_count=0;
    implement_query2();
    cout<<lru_page_fault_count<<" "<<mfu_page_fault_count<<endl;
    lru_page_fault_count=0;
    mfu_page_fault_count=0;
    implement_query3();
    cout<<lru_page_fault_count<<" "<<mfu_page_fault_count<<endl;
    lru_page_fault_count=0;
    mfu_page_fault_count=0;
    implement_query4();
    cout<<lru_page_fault_count<<" "<<mfu_page_fault_count<<endl;
}