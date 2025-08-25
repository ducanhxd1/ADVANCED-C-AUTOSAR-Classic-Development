#ifndef  _BINARYTREE_H_
#define  _BINARYTREE_H_

/**
* @brief Cấu trúc lưu thông tin cây nhị phân
* @details
* - Dùng để tạo ra và quản lý các nhánh (node) trái/phải của binary tree dựa trên node giữa (gốc)
*/
typedef struct CenterPoint {
    int value;                 // Giá trị của node          
    struct CenterPoint *left;  // con trỏ đến node con bên trái
    struct CenterPoint *right; // con trỏ đến node con bên phải
}CenterPoint;


#endif