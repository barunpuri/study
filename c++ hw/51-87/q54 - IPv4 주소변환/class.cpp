#include <iostream>
#include <string>
#include <cstdlib>//atoi
#include <stdio.h>

//#define __DEBUG__

class IPv4 {

private:
	unsigned int data_;

protected: // 클래스 안에 선언된 함수에서만 사용할 함수
	void seperate(const std::string& _ip_string, std::string _digit[4]);
	void seperate(const unsigned int _ip_data, unsigned char _data[4]);

public:
	void set(const std::string& _ip_string);
	void get(unsigned int& _data) { _data = data_; }	
	//unsigned int get() const { return data_; }

	void set(const unsigned int _ip_data) { data_ = _ip_data; }
	void get(std::string& _ip_string);	
	//std::string get() const { return ; }

};

void IPv4::seperate(const std::string& _ip_string, std::string _digit[4])
{
	int idx = 0;	

	for(int i=0; i<_ip_string.length(); ++i)
	{
		const char ch = _ip_string[i]; 
		
		if(ch != '.') 	_digit[idx] += ch;
		else		++idx; 
		
	}

#ifdef __DEBUG__	//__DEBUG__ 가 정의되어 있을때 #define __DEBUG__ 라고 정의되있으면 if~endif 내용이 실행
	for(idx=0; idx<4; ++idx)
		std::cout <<idx << ": " << _digit[idx] <<std::endl;
#endif

}

void IPv4::seperate(const unsigned int _ip_data, unsigned char _data[4])
{
	const unsigned char* p = (const unsigned char *)&_ip_data;

	_data[0] = p[0];
	_data[1] = p[1];
	_data[2] = p[2];
	_data[3] = p[3];
}


void IPv4::set(const std::string& _ip_string)
{
	std::string 	digit[4];
	int 		num_digit[4];
	unsigned int	res;
	unsigned char* 	p = (unsigned char *) &res;

	seperate(_ip_string, digit);
	
	for(int i=0; i<4; ++i)
		num_digit[i] = atoi(digit[i].c_str());  //atoi : char -> int
							// c_str : c++->c style string
#ifdef __DEBUG__
	for(int i=0; i<4; ++i)
		std::cout << i << "-th num-digit: " << num_digit[i] << std::endl;
#endif
	p[3] = (unsigned char)num_digit[0];
	p[2] = (unsigned char)num_digit[1];
	p[1] = (unsigned char)num_digit[2];
	p[0] = (unsigned char)num_digit[3];

	data_ = res;
}

void IPv4::get(std::string& _ip_string)
{
	
	char		str[100];

	unsigned char digit_data[4];

	seperate(data_, digit_data);
	
	sprintf(str, "%d.%d.%d.%d", digit_data[3], digit_data[2], digit_data[1], digit_data[0]);

	_ip_string = str;

}


int main() 
{
	IPv4		ip_v4;
	std::string 	ip;
	unsigned int 	data;

	ip = "123.111.8.1";
	
	ip_v4.set(ip);
	ip_v4.get(data);

	ip_v4.set(data);
	ip_v4.get(ip);

	std::cout << data << std::endl;
	std::cout << ip << std::endl;

	return 0;
}

