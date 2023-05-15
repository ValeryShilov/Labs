#pragma once
#include <iostream>
#include <string>
using namespace std;

class Error
{
public:
	virtual void what(){ };
};

class IndexError : public Error //error in index vector
{
protected:
	string msg;
public:
	IndexError() { msg = "Index Error\n"; }
	virtual void what() { cout << msg; }
};

class SizeError :public Error
{
protected:
	string msg;
public:
	SizeError() { msg = "Size Error\n"; }
	virtual void what() { cout << msg; }
};

class MaxSizeError : public SizeError
{
protected:
	string msg_;
public:
	MaxSizeError() { SizeError(); msg_ = "size>MAX SIZE\n"; }
	virtual void what() { cout << msg << msg_; }
};

class NegSizeError : public SizeError
{
protected:
	string msg_;
public:
	NegSizeError() { SizeError(); msg_ = "n cannot negative\n"; }
	virtual void what() { cout << msg << msg_; }
};

class NSizeError : public SizeError
{
protected:
	string msg_;
public:
	NSizeError() { SizeError(); msg_ = "n cannot more size\n"; }
	virtual void what() { cout << msg << msg_; }
};

class EmptySizeError :public SizeError 
{
protected:
	string msg_;
public:
	EmptySizeError() { SizeError(); msg_ = "Vector is empty\n"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError1 :public IndexError 
{
protected:
	string msg_;
public:
	IndexError1() { IndexError(); msg_ = "index <0\n"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError2 :public IndexError 
{
protected:
	string msg_;
public:
	IndexError2() { IndexError(); msg_ = "index>size\n"; }
	virtual void what() { cout << msg << msg_; }
};
