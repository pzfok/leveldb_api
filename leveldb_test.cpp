#include <iostream>
#include <leveldb/db.h>
#include <sstream>
using namespace std;


int main(){
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  string dbpath = "test2db";
  leveldb::Status status = leveldb::DB::Open(options, dbpath, &db);
  assert(status.ok());
  string key1 = "wyh";
  string key2 = "liyc7711";
  cout<< "zhichibuzhichi"<<endl;

  string value;
  leveldb::Status s;
  stringstream convert;
  for(int i=0; i<100000; i++){
    convert << i;
    string key = key1 + convert.str();
    s = db->Put(leveldb::WriteOptions(), key, key2);
  }
  //cout<< s<<endl;
  s = db->Get(leveldb::ReadOptions(), key1, &value);
  
  cout<< value <<endl;
  delete db;
  
  return 0;

}
