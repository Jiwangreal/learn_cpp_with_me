class IsEqualld
{
public:
    explicit IsEqualld(unsigned int id) : id_(id) {}
    //const std::string, unsigned int��map����������
    bool operator()(const std::pair<const std::string, unsigned int>& it) const
    {
        return it.second == id_;
    }

private:
    unsigned int id_;//��״̬�ĺ�������
};

std::string SymbolTable::GetSymbolName(unsigned int id) const
{
    //�����������ǣ�std::string, unsigned int
    //һ��mapʹ��key�����ң�����ʹ�õڶ����ֶ�������
    std::map<const std::string, unsigned int>::const_iterator it;
    it = find_if(dictionary_.begin(), dictionary_.end(), IsEqualld(id));

    //�Ҳ����Ļ�
    if (it == dictionary_.end())
    {
        throw Exeception("Internale error: missing entry int symbol table");
    }
    return it->first;
}