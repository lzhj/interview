#include "qh_string.h"

#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
    {
        init();
    }

    string::string( const char* s )
    {
        if(!s){
           init();
        }else{
            int len = stlen(s);
            data_ = new char[len+1];
            strcpy(data_, s);
            len_ = len;
        }
    }

    string::string( const char* s, size_t len )
    {
        if(!s || len == 0){
            init();
        }else{
            size_t len_s = strlen(s);
            if(len_s >= len){
                data_ = new char[len+1];
                strncpy(data_, s, len);
                len_ = len;
            }else{
                data_ = new char[len+1];
                strcpy(data_, s);
                for(size_t i = len_s; i < len+1; ++i){
                    data_[i] = '\0';
                }
                len_ = len;
            }
        }
    }

    string::string( const string& rhs )
    {
        size_t len_rhs = strlen(rhs.data_);
        data_ = new char[len_rhs+1];
        strcpy(data_, rhs.data_);
        len_ = len_rhs;
    }

    string& string::operator=( const string& rhs )
    {
        if(this != &rhs){
            delete[] data_;
            data_ = 0;

            size_t len_rhs = strlen(rhs.data_);
            data_ = new char[len_rhs+1];
            strcpy(data_, rhs.data_);
            len_ = len_rhs;
        }
        return *this;
    }

    string::~string()
    {
        delete[] data_;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        return data_;
    }

    char& string::operator[]( size_t index )
    {
        return data_[index];
    }
    const char& string::operator[](size_t index) const
    {
        return data_[index];
    }
    void string::init()
    {
        data_ = new char[0];
        len_ = 0;
    }
}
