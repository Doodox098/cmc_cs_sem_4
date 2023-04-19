#include <string>
#include <stdexcept>
#include <sstream>

class StringView {
private:
    /// Iterator
    template<typename ValueType>
    class SVIterator
    {
        friend StringView;
    private:
        ValueType* p;
    public:
        typedef ValueType value_type;
        typedef ValueType& reference;
        typedef std::ptrdiff_t difference_type;

        SVIterator(ValueType* p) : p(p) {};
        SVIterator(const SVIterator &it) : p(it.p) {}

        bool operator!=(SVIterator const& other) const
        {
            return p != other.p;
        }
        bool operator==(SVIterator const& other) const
        {
            return p == other.p;
        }
        ValueType& operator*() const {
            return *p;  
        }
        SVIterator& operator++() {
            ++p;
            return *this;
        }
        SVIterator operator++(int _) {
            SVIterator tmp{*this};
            ++p;
            return tmp;
        }
        SVIterator& operator--() {
            --p;
            return *this;
        }
        SVIterator operator--(int _) {
            SVIterator tmp{*this};
            --p;
            return tmp;
        }
        SVIterator& operator+=(size_t idx) {
            p += idx;
            return *this;
        }
        SVIterator& operator-=(size_t idx) {
            p -= idx;
            return *this;
        }
        ValueType& operator[](size_t idx) {
            return *(*this + idx);
        }

        operator SVIterator<const char>(){
            SVIterator<const char> tmp(this->p);
            return tmp;
        }

        friend inline SVIterator<ValueType>& operator+ (SVIterator<ValueType> &it1, size_t idx){
            ReverseSVIterator tmp{it1};
            tmp.p += idx;
            return tmp;
        }
        friend inline SVIterator<ValueType>& operator+ (size_t idx, SVIterator<ValueType> &it1){
            ReverseSVIterator tmp{it1};
            tmp.p += idx;
            return tmp;
        }
        friend inline SVIterator<ValueType>& operator- (SVIterator<ValueType> &it1, size_t idx){
            ReverseSVIterator tmp{it1};
            tmp.p -= idx;
            return tmp;
        }
        friend inline ptrdiff_t operator- (SVIterator<ValueType> &it1, SVIterator<ValueType> &it2){
            ptrdiff_t tmp = it1.p - it2.p;
            return tmp;
        }
        friend bool operator == (const SVIterator &it1, const SVIterator &it2) {
            if (it1.p == it2.p)
                return true;
            return false;
        }
        friend bool operator != (const SVIterator &it1, const SVIterator &it2) {
            if (it1.p != it2.p)
                return true;
            return false;
        }

        friend auto operator <=> (const SVIterator &it1, const SVIterator &it2)
        {
            if (it1.p < it2.p)
                return std::strong_ordering::less;
            else if (it1.p > it2.p)
                return std::strong_ordering::greater;
            else
                return std::strong_ordering::equivalent;
        }
    };
    /// Reverse Iterator
    template<typename ValueType>
    class ReverseSVIterator
    {
        friend StringView;
    private:
        ValueType* p;
    public:
        ReverseSVIterator(ValueType* p) : p(p) {};
        ReverseSVIterator(const ReverseSVIterator &it) : p(it.p) {}

        bool operator!=(ReverseSVIterator const& other) const
        {
            return p != other.p;
        }
        bool operator==(ReverseSVIterator const& other) const
        {
            return p == other.p;
        }
        ValueType& operator*() const {
            return *(p - 1);
        }
        ReverseSVIterator& operator++() {
            --p;
            return *this;
        }
        ReverseSVIterator operator++(int _) {
            ReverseSVIterator tmp{*this};
            --p;
            return tmp;
        }
        ReverseSVIterator& operator--() {
            ++p;
            return *this;
        }
        ReverseSVIterator operator--(int _) {
            ReverseSVIterator tmp{*this};
            ++p;
            return tmp;
        }
        ReverseSVIterator& operator+=(size_t idx) {
            p -= idx;
            return *this;
        }
        ReverseSVIterator& operator-=(size_t idx) {
            p += idx;
            return *this;
        }
        ValueType& operator[](size_t idx) {
            return *(*this + idx);
        }

        operator ReverseSVIterator<const char>(){
            ReverseSVIterator<const char> tmp{this->p};
            return tmp;
        }

        friend ReverseSVIterator<ValueType>& operator+ (ReverseSVIterator<ValueType> &it1, size_t idx){
            ReverseSVIterator tmp{it1};
            tmp.p -= idx;
            return tmp;
        }
        friend ReverseSVIterator<ValueType>& operator+ ( size_t idx, ReverseSVIterator<ValueType> &it1){
            ReverseSVIterator tmp{it1};
            tmp.p -= idx;
            return tmp;
        }
        friend ReverseSVIterator<ValueType>& operator- (ReverseSVIterator<ValueType> &it1, size_t idx){
            ReverseSVIterator<ValueType> tmp{it1};
            tmp.p += idx;
            return tmp;
        }
        friend ptrdiff_t operator- (ReverseSVIterator<ValueType> &it1, ReverseSVIterator<ValueType> &it2){
            ptrdiff_t tmp = it2.p - it1.p;
            return tmp;
        }

        friend bool operator == (const ReverseSVIterator &it1, const ReverseSVIterator &it2) {
            if (it1.p == it2.p)
                return true;
            return false;
        }
        friend bool operator != (const ReverseSVIterator &it1, const ReverseSVIterator &it2) {
            if (it1.p != it2.p)
                return true;
            return false;
        }

        friend auto operator <=> (const ReverseSVIterator &it1, const ReverseSVIterator &it2)
        {
            if (it1.p < it2.p)
                return std::strong_ordering::less;
            else if (it1.p > it2.p)
                return std::strong_ordering::greater;
            else
                return std::strong_ordering::equivalent;
        }
    };

    char* view_begin;
    size_t count;

public:
    typedef SVIterator<char> iterator;
    typedef SVIterator<const char> const_iterator;
    typedef ReverseSVIterator<char> reverse_iterator;
    typedef ReverseSVIterator<const char> const_reverse_iterator;
    StringView(std::string &s, size_t begin = 0, size_t count = std::string::npos)
    {
        if (begin >= s.size()) {
            this->view_begin = nullptr;
        } else {
            this->view_begin = s.data();
        }
        if (count >= s.size() - begin) {
            this->count = s.size() - begin;
        } else {
            this->count = count;
        }
    }
    StringView(const StringView &sv, size_t begin = 0, size_t count = std::string::npos)
    {
        if (begin >= sv.count) {
            this->view_begin = nullptr;
            this->count = 0;
        } else {
            this->view_begin = sv.view_begin;
            if (count >= sv.count - begin) {
                this->count =  sv.count - begin;
            } else {
                this->count = count;
            }
        }
    }

    size_t length() const
    {
        return count;
    }
    size_t size() const
    {
        return count;
    }
    char& operator[] (size_t idx)
    {
        return view_begin[idx];
    }
    const char& operator[] (size_t idx) const
    {
        return view_begin[idx];
    }
    char& at(size_t idx)
    {
        if (idx < count)
            return view_begin[idx];
        else
        {
            std::ostringstream ostream(std::ostringstream::ate);
            ostream << "StringView::at: idx (which is " << idx << ") >= this->size() (which is " << this->size() << ")";
            throw std::out_of_range(ostream.str());
        }
    }
    const char& at(size_t idx) const
    {
        if (idx < count)
            return view_begin[idx];
        else
        {
            std::ostringstream ostream(std::ostringstream::ate);
            ostream << "StringView::at: idx (which is " << idx << ") >= this->size() (which is " << this->size() << ")";
            throw std::out_of_range(ostream.str());
        }
    }
    std::string str(size_t begin = 0, size_t count = std::string::npos) const
    {
        std::string tmp;
        if (this->view_begin == nullptr)
        {
            return tmp;
        }
        if (begin >= this->count) {
            return tmp;
        }
        if (count >= this->count - begin) {
            count =  this->count - begin;
        }
        tmp.append(this->view_begin + begin, count);
        return tmp;
    }

    iterator begin() {
        iterator it(view_begin);
        return it;
    }
    iterator end() {
        iterator it(view_begin + count);
        return it;
    }
    const_iterator cbegin() {
        const_iterator it(view_begin);
        return it;
    }
    const_iterator cend() {
        const_iterator it(view_begin + count);
        return it;
    }

    reverse_iterator rbegin() {
        reverse_iterator it(view_begin + count);
        return it;
    }
    reverse_iterator rend() {
        reverse_iterator it(view_begin);
        return it;
    }
    const_reverse_iterator crbegin() {
        const_reverse_iterator it(view_begin + count);
        return it;
    }
    const_reverse_iterator crend() {
        const_reverse_iterator it(view_begin);
        return it;
    }

    friend auto operator <=> (const StringView sv1, const StringView sv2) ;

    auto operator=(StringView &sv1) = delete;
    auto operator=(StringView sv1) = delete;
};

auto operator <=> (const StringView sv1, const StringView sv2)
{
    if (sv1.str() < sv2.str())
        return std::strong_ordering::less;
    else if (sv1.str() > sv2.str())
        return std::strong_ordering::greater;
    else
        return std::strong_ordering::equivalent;
}
