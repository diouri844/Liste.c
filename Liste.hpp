class Liste{
    private:
        int length;
        float* tab;
    public:
        //constructeur :
        Liste();
        // Surcharge du constructeur :
        Liste(int len);
        Liste(int len,int nbr);
        // Methodes menmbre :
        int len();
        void see();
        float get(int index);
        float* get_tab();
        float max();
        float min();
        int in(float item);
        int occur(float item);
        void set(float item,int index);
        int index(float item);
        void append(float item);
        void pop();
        void insert(int index,float item);
        void delet(int index);
        void sort(bool reverse);
        Liste extract(int in_start,int in_end);
        void extend(float* temp);
        // Surcharge des methodes:
        void see(int index);
        float max(int index);
        float min(int index);
        float max(int in_start,int in_end);
        float min(int in_start,int in_end);
};