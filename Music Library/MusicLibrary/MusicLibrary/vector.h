#ifndef   VEC
#define VEC

template<typename T>
class Vector
{
protected:
	T *values;
	int size,maxSize;
public:
	Vector() :size(size), maxSize(10) { values = new T[10]; };
	void add(T value);
	void remove(T value);
	T& get(int i);
	int get_size() { return size; };
	~Vector();
	
};

#endif // !1

template<typename T>
 void Vector<T>::add(T value)
{
	 if (size > maxSize-1)
	 {
		 T *values1;
		 values1 = new T[maxSize + 10];
		 for (int i = 0; i < size; i++)
		 {
			 values1[i] = values[i];
		 }
		 delete []values;
		 maxSize = maxSize + 10;
		 values = values1;
	 }
	 values[size] = value;
	 size++;
}

 template<typename T>
 void Vector<T>::remove(T value)
 {
	 int pos = 0;
	 for (int i = 0; i < size; i++)
	 {
		 if (values[i] == value)
		 {
			 values[pos++] = values[i];
		 }		 
	 }
	 size = pos;
 }

 template<typename T>
T& Vector<T>::get(int i)
 {
	 return values[i];
 }

 template<typename T>
 Vector<T>::~Vector()
 {
	 for (int i = 0; i < size; i++)
	 {
		 delete values[i];
	 }
	 delete[]values;
 }
