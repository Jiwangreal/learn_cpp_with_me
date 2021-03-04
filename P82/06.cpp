class IsEqualld
{
public:
    explicit IsEqualld(unsigned int id) : id_(id) {}
    //const std::string, unsigned int是map容器的类型
    bool operator()(const std::pair<const std::string, unsigned int>& it) const
    {
        return it.second == id_;
    }

private:
    unsigned int id_;//有状态的函数对象
};

std::string SymbolTable::GetSymbolName(unsigned int id) const
{
    //迭代器类型是：std::string, unsigned int
    //一般map使用key来查找，这里使用第二个字段来查找
    std::map<const std::string, unsigned int>::const_iterator it;
    it = find_if(dictionary_.begin(), dictionary_.end(), IsEqualld(id));

    //找不到的话
    if (it == dictionary_.end())
    {
        throw Exeception("Internale error: missing entry int symbol table");
    }
    return it->first;
}