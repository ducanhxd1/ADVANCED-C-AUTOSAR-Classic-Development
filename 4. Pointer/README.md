</details>
<details>
  <summary><h2>Pointer</h2></summary>

- Con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn.
- Thông qua con trỏ có thể thay đổi giá trị tại biến mà nó trỏ tới

- Cách khai báo:

```C
int x = 10;
int *ptr = &x;  // ptr giờ đây chứa địa chỉ của x
*ptr =5;
>> x bằng5
```
- Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch.
- `Môi trường Windows 32 bit: 4 bytes`
- `Môi trường Windows 64 bit: 8 bytes`

```C
int main()
{
    int *ptr;
    printf("Size of pointer: %d bytes\n", sizeof(ptr));    
    return 0;

}

```
- Ứng dụng để truyền tham trị .
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>

// Hàm swap: Đổi giá trị của hai biến sử dụng con trỏ
void swap(int *a, int *b)
{
    int tmp = *a;   // Lưu giá trị của biến a vào biến tạm thời tmp
    *a = *b;        // Gán giá trị của biến b cho biến a
    *b = tmp;       // Gán giá trị của biến tạm thời tmp (ban đầu là giá trị của a) cho biến b
}

// Hàm main: Hàm chính của chương trình
int main()
{
    int a = 10, b = 20; // Khai báo và khởi tạo hai biến a và b

    swap(&a, &b);       // Gọi hàm swap để đổi giá trị của a và b

    // In ra giá trị của a và b sau khi đã đổi giá trị
    printf("value a is: %d\n", a);
    printf("value b is: %d\n", b);

    return 0; // Kết thúc chương trình
}

```
</details>

**Các loại con trỏ**
- Con trỏ hàm(Hàm con trỏ)
- Con trỏ void.
- Con trỏ hằng.
- Hằng Con trỏ .
- Con trỏ trỏ tới con trỏ.
- Con trỏ NULL.

**Con trỏ hàm**
- Hàm (function) bản chất là 1 địa chỉ vùng nhớ
- Con trỏ hàm lưu trữ địa chỉ của một hàm, tương tự như cách mà con trỏ thông thường lưu trữ địa chỉ của biến.
- Bạn có thể sử dụng con trỏ hàm để gọi hàm hoặc chuyển nó như một tham số cho hàm khác.

**Chức năng**
- Gọi hàm thông qua con trỏ: Thay vì gọi hàm trực tiếp,có thể gọi thông qua con trỏ hàm.
- Chuyển hàm làm tham số: Một hàm có thể nhận con trỏ hàm làm tham số để quyết định hàm nào sẽ được gọi trong quá trình thực thi.
 <details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>

// Hàm mẫu
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    // Khai báo con trỏ hàm với cú pháp: <kiểu dữ liệu trả về> (*<tên con trỏ>)(<kiểu dữ liệu đối số 1>, <kiểu dữ liệu đối số 2>, ...)
    int (*operation)(int, int);

    // Gán địa chỉ của hàm add cho con trỏ hàm
    operation = add;

    // Sử dụng con trỏ hàm để gọi hàm add
    printf("Result: %d\n", operation(5, 3)); // In ra: Result: 8

    // Gán địa chỉ của hàm subtract cho con trỏ hàm
    operation = subtract;

    // Sử dụng con trỏ hàm để gọi hàm subtract
    printf("Result: %d\n", operation(5, 3)); // In ra: Result: 2

    return 0;
}

```
</details>

**Hàm con trỏ**
- Hàm con trỏ là một hàm mà tham số của nó là một con trỏ hàm.
- Điều này cho phép bạn truyền một hàm cụ thể vào một hàm khác để thực hiện các tác vụ động linh hoạt
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
// Hàm con trỏ làm tham số cho một hàm khác
void processNumbers(int (*operation)(int, int), int a, int b) {
    int result = operation(a, b);
    printf("Result: %d\n", result);
}

// Hàm mẫu 1
int add(int a, int b) {z
    return a + b;
}

int main() {
    int a = 10, b = 5;
    processNumbers(add, a, b);
    

    return 0;
}
```
</details>

**Con trỏ void**
- Void Pointer có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.
- Vì nó không có thông tin về loại dữ liệu mà nó trỏ tới
- Cách ép kiểu dữ liệu từ con trỏ Void:`(int*)(ptr)` đang ép về kiểu int.
- Dùng trong bài toán , nhiều kiểu dữ liệu mà không muốn dùng nhiều loại con trỏ trỏ tới chúng .
- Trong ví dụ bên dưới, con trỏ ptr trỏ tới tất cả các biến.
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a+b;
}

int main() {
   
    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    ptr = sum;
    printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));

    void *ptr1[] = {&value, &test, &letter , sum, array};

    printf("value: %d\n", *(int*)ptr1[0]);

    printf("value: %c\n", *((char*)ptr1[4]+1));

    return 0;
}

```
</details>

**Con trỏ hằng- Pointer to Constant**
- không thể thay đổi giá trị tại biến mà nó đang trỏ đến.
- Thường  dùng khi làm việc với các vùng nhớ không được phép thay đổi
- Dùng để truyền tham số vào hàm mà không muốn hàm đó thay đổi giá trị  tham số.
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>

// Hàm in mảng sử dụng con trỏ đến hằng
void printArray(const int *array, int size) {
	//array[0]=2;// lỗi
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int values[] = {10, 20, 30, 40, 50};
    int size = sizeof(values) / sizeof(values[0]);

    // Gọi hàm printArray với con trỏ đến mảng values
    printArray(values, size);

    return 0;
}
// nếu không dùng con trỏ hằng thì có thể thay đổi được dữ liệu từ hàm

```
</details>


- So sánh:

| Con trỏ thường | Con trỏ hằng|
|-------|-------|
| Có thể thay đổi giá trị | không thể thay đổi giá trị |

```C
 int *ptr;// con trỏ thường
 const int *ptr1;//con trỏ hằng
 x=5;
 ptr=&x;
 *ptr=10;
 printf("x la %d",x);//x =10
 *ptr1 =10;//lỗi , vì nó làm thay đổi giá trị biến
```
**Hằng con trỏ- Constant Pointer**
- Khai báo:`int *const const_ptr = &value;`
- Đặc điểm:
	- muốn con trỏ luôn trỏ đến một đối tượng cụ thể trong suốt vòng đời của nó.
	- Khi hằng con trỏ đã trỏ đến 1 địa chỉ nào rồi,nó không thể trỏ tới bất kỳ 1 địa chỉ nào khác.
	- Có thể thay đổi được giá trị tại địa chỉ đã khởi gán ban đầu.

<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
#include <stdlib.h>
int main() {    
	int value = 5;    
	int test = 15;    
	int *const const_ptr = &value;   
	printf("value: %d\n", *const_ptr);    
	*const_ptr = 7   
	printf("value: %d\n", *const_ptr);   
	const_ptr = &test; // LỖI vì đã cố định vào value
	return 0;
}
```

</details>


**Pointer to Pointer**
- là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. 
- Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. 
- Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.

<details>
<summary>Ví dụ:</summary>

```C
int test = 5;	//Address: 0x01
			 	//Value:	5
int *ptr = &test;//Address: 0x02
			 	//Value:	0x01
int **ptr1=&ptr;//Address: 0x03
			 	//Value:	0x01

#include <stdio.h>

int main() {
    int x = 10;
    int *ptr1 = &x;  // Con trỏ ptr1 trỏ đến biến x
    int **ptr2 = &ptr1;  // Con trỏ ptr2 trỏ đến con trỏ ptr1

    printf("Địa chỉ x: %p\n", &x);   //Địa chỉ x: 0x7ffe88cb3ab4
    printf("gia tri ptr1: %p\n", ptr1);//gia tri ptr1: 0x7ffe88cb3ab4
    printf("Địa chỉ con trỏ ptr1: %p\n", &ptr1);//Địa chỉ con trỏ ptr1: 0x7ffe88cb3ab8
    printf("Giá trị của ptr2 (địa chỉ của ptr1): %p\n", ptr2)//Giá trị của ptr2 (địa chỉ của ptr1): 0x7ffe88cb3ab8

    return 0;
}

```
</details>

**NULL Pointer**
- Khai báo:`int *ptr = NULL; `
- NULL pointer là một con trỏ không trỏ đến bất kỳ vùng nhớ cụ thể nào.
- Trong vđk khởi tạo con trỏ phải gán NULL
- Trước khi xài thì phải kiểm tra nó là NULL hay không.
- Lý do nếu kiểm tra không phải là NULL thì con trỏ đang trỏ tới 1 giá trị nào đó ,Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) làm sai chương trình.
- Khi xài xong 1 pointer thì phải gán nó bằng Null, để tránh sử dụng giá trị cũ của con trỏ.

<details>
<summary>Ví dụ:</summary>

```C

#include <stdio.h>
int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    int score_game = 5;
    if (ptr == NULL)
    {
        ptr = &score_game;
        *ptr = 30;
        ptr = NULL;
    }
}

```
</details>
