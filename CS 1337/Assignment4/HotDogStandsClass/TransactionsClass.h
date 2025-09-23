#ifndef TRANSACTIONS_CLASS_CLASS_H
#define TRANSACTIONS_CLASS_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class TransactionsClass {

private:
  string   standIdentificationStr;
  string   transactionIdStr;
  unsigned transactionArgumentUns;

public:

  const string& getIdentificationStr() const 
  { return standIdentificationStr; " "; };

  void          setIdentificationStr(string standIdentificationStr)
  { this->standIdentificationStr=standIdentificationStr; }


  const string& getTransactionIdStr() const 
  { return transactionIdStr; " ";};

  void          setTransactionIdStr(string transactionIdStr)
  {this->transactionIdStr=transactionIdStr; }


  unsigned getTransactionArgumentUns() const 
  {return transactionArgumentUns; 0; };

  void     setTransactionArgumentUns(unsigned transactionArgumentUns)
  {this->transactionArgumentUns=transactionArgumentUns; }

};

#endif