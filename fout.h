#ifndef FOUT
#define FOUT
#include <iostream>
#include <iomanip>
#include "structures.h"
using namespace std;

template<typename charT, typename traits = std::char_traits<charT> >
class center_helper {
    std::basic_string<charT, traits> str_;
public:
    center_helper(std::basic_string<charT, traits> str) : str_(str) {}
    template<typename a, typename b>
    friend std::basic_ostream<a, b>& operator<<(std::basic_ostream<a, b>& s, const center_helper<a, b>& c);
};

template<typename charT, typename traits = std::char_traits<charT> >
center_helper<charT, traits> centered(std::basic_string<charT, traits> str) {
    return center_helper<charT, traits>(str);
}

center_helper<std::string::value_type, std::string::traits_type> centered(const std::string& str) {
    return center_helper<std::string::value_type, std::string::traits_type>(str);
}

template<typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& s, const center_helper<charT, traits>& c) {
    std::streamsize w = s.width();
    if (w > c.str_.length()) {
        std::streamsize left = (w + c.str_.length()) / 2;
        s.width(left);
        s << c.str_;
        s.width(w - left);
        s << "";
    } else {
        s << c.str_;
    }
    return s;
}

class fout
{
    private:
        int width;
        ostream& stream_obj;

    public:
        fout(ostream& obj, int w): width(w), stream_obj(obj) {}

        template<typename T>
        fout& operator<<(const T& output)
        {   
            stream_obj << setw(width) << centered(output);

            return *this;
        }

        fout& operator<<(const int& output)
        {   
            stream_obj << setw(8)<< centered(to_string(output));

            return *this;
        }

        fout& operator<<(const Roles& output)
        {   
            stream_obj << setw(8)<< centered(to_string(output));

            return *this;
        }

        fout& operator<<(const Genres& output)
        {   
            stream_obj << setw(8)<< centered(to_string(output));

            return *this;
        }

        fout& operator<<(const BookTypes& output)
        {   
            stream_obj << setw(8)<< centered(to_string(output));

            return *this;
        }

        fout& operator<<(ostream& (*func)(ostream&))
        {
            func(stream_obj);
            return *this;
        }
};

#endif