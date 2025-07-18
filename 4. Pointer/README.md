</details>
<details>
  <summary><h3>Con trỏ(pointer)</h3></summary>

**Con trỏ là gì** 
- Là 1 biến ,không lưu giá trị bình thường, nó lưu địa chỉ.
- Cách khai báo con trỏ:<kiểu dữ liệu> * <tên biến>
- kiểu dữ liệu con trỏ phải trùng kiểu dữ liệu biến nó trỏ tới.
- Ví dụ:
```C
 int main(){
	int a =10;
	int *ptr =&a;//&lấy địa chỉ
	return 0;
 }

```



- Nếu không dùng con trỏ thì giá trị a,btrong hàm cục bộ sẽ bị thu hồi ,
và giá trị x,y không thay đổi được.
- Ví dụ bài toán hoán vị:
```C
	int swap(int *a, int *b) {
		int temp;
		temp=*a;
		*a=*b;
		*b=temp;
		printf("dia chi cua a la : %p\n",a);
		printf("gia tri cua a la : %d\n",*a);
	}
	int subtract(int a, int b) {
		return a - b;
	}

	int main() {
	
		int x,y;
		x=20;y=15;
		swap(&x,&y);
		printf("%d,%d",x,y);

		return 0;
	}
```


- Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
- Kích thước của các biến con trỏ có khác nhau không? Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
		- `Môi trường Windows 32 bit: 4 bytes`
        - `Môi trường Windows 64 bit: 8 bytes`

### Các loại con trỏ:

- ***Con trỏ hàm (Function Pointers):*** Dùng để lưu trữ và gọi các hàm thông qua con trỏ.
	```c
	void tong (int a, int b){
		printf("tong %d va %d = %d\n",a,b,a+b);
	}
	void hieu (int a, int b){
		printf("tong %d va %d = %d\n",a,b,a-b);
	}

	 

	int main() {
		void (*ptr)(int, int);
		ptr =&tong;
		ptr(8,6);
	 

		return 0;
	}

	```
- ***Con trỏ NULL:*** Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
	```c
	int *p2; //con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
	int *p3 = NULL; //con trỏ null không trỏ đến vùng nhớ nào
	int *p4 = null; // Lỗi "null" phải viết in hoa
	```
- ***Con trỏ đến con trỏ(pointer to pointer):*** Con trỏ này dùng để lưu địa chỉ của con trỏ khác.
	```c
	int x = 10;
    int *p1 = &x;     // Con trỏ p1 trỏ đến biến x và giá trị của p1 chỉnh là địa chỉ của biến x
    int **p2 = &p1;	 // Con trỏ p2 trỏ đến con trỏ p1 và lưu địa chỉ của con trỏ p1 vào p2  

    printf("Giá trị của x: %d\n", *p1); //Giá trị của x: 10
    printf("Địa chỉ của x: %p\n", p1); //Địa chỉ của x: 0x7ffee2a697a8 
    printf("Giá trị của x: %d\n", **p2); //Giá trị của x: 10
    printf("Địa chỉ của p1: %p\n", p2); //Địa chỉ của p1: 0x7ffee2a697a0
	```
- ***Con trỏ hằng (Constant Pointers):*** Không thể thay đổi giá trị mà nó trỏ tới, nhưng có thể thay đổi địa chỉ mà nó trỏ tới.
	```c
	int num = 10; 
	const int *ptr = &num; //thay đổi được địa chỉ của num nhưng không thay đổi được giá trị '10' của num
	```
- ***Con trỏ void (Void Pointers):*** Con trỏ void có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.


	```c
	int num = 10;
	float f = 3.14;
	void *ptr;
	ptr = &num;
	printf("num = %d\n",(int*)ptr);
	ptr = &f;
	printf("f = %f\n",(float*)ptr);
	```

- ***Con trỏ vào hàm (Pointers to Functions):*** Lưu trữ địa chỉ của một hàm cụ thể để gọi hàm thông qua con trỏ.
	```C
	int add(int a, int b) {
		return a + b;
	}
	int subtract(int a, int b) {
		return a - b;
	}

	void performOperation(int a, int b, int (*operation)(int, int)) {
		int result = operation(a, b);
		printf("Result: %d\n", result);
	}

	int main() {
		int a = 5, b = 3;

		performOperation(a, b, add);
		performOperation(a, b, subtract);

		return 0;
	}

	```
- ***Con trỏ hàm parameter (Function Pointer Parameters):*** Truyền một hàm như một tham số cho một hàm khác.
	```C
	void greet() {
		printf("Hello, World!\n");
	}

	void performAction(void (*action)()) {
		action();
	}

	int main() {
		performAction(greet);

		return 0;
	}

	```
### Lưu ý khi sử dụng con trỏ
- Khi khởi tạo con trỏ NULL: Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi.
- Không nên sử dụng con trỏ khi chưa được khởi tạo: Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.
- Sử dụng biến con trỏ sai cách.

### Tác dụng của con trỏ

- Chúng ta có thể sử dụng con trỏ để thay đổi giá trị vùng con trỏ trỏ đến.
- Giả sử mình khởi tạo 1 biến số c.
```c
int c = 22; // khởi tạo giá trị ban đầu của c = 22
```
- Vậy chúng ta có bao nhiêu cách để thay đổi giá trị biến c.
- Cách 1: thay đổi trực tiếp
`c = 11;`
- Cách 2: thay đổi gián tiếp qua 1 con trỏ
```c
int *pc = &c;    // trỏ con trỏ pc tới vùng nhớ của biến c
*pc = 11;        // *pc tương đương với giá trị của biến c 
```
</details>