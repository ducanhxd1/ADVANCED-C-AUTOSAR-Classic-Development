#include <stdio.h>
#include <stdint.h>

#define GENDER  1 << 0 // Bit 0 : Giới tính (0 = nữ, 1 = nam)   // 0b00000001
#define AGE     1 << 1 // Bit 1 : Tuổi (0 = trẻ, 1 = già)       // 0b00000001 << 1 = 0b00000010
#define STATUS  1 << 2 // Bit 2 : Trạng thái (0 = không hoạt động, 1 = hoạt động)
#define ROLE    1 << 3 // Bit 3 : Vai trò (0 = nhân viên, 1 = quản lý)

#define FEATURE1 1 << 4 // Bit 4 : Tính năng (0 = không có, 1 = có)
#define FEATURE2 1 << 5 // Bit 5 : Tính năng (0 = không có, 1 = có)
#define FEATURE3 1 << 6 // Bit 6 : Tính năng (0 = không có, 1 = có)
#define FEATURE4 1 << 7 // Bit 7 : Tính năng (0 = không có, 1 = có)

// đặt bit
void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature; // Sử dụng OR để bật tính năng
}

// xóa bit
void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature; // Sử dụng AND với NOT để tắt tính năng
}

// kiểm tra bit
int isFeatureEnabled(uint8_t *features, uint8_t feature ){
    return (*features & feature) != 0; // Sử dụng AND để kiểm tra tính năng
}

void listFeatures(uint8_t features) {
    printf("Current Features:\n");
    if (isFeatureEnabled(&features, GENDER)) {
        printf("- Gender\n");
    }

    if (isFeatureEnabled(&features, AGE)) {
        printf("- Age\n");
    }

    if (isFeatureEnabled(&features, STATUS)) {
        printf("- Status\n");
    }

    if (isFeatureEnabled(&features, ROLE)) {
        printf("- Role\n");
    }

    for (int i = 1; i <= 4; i++) {
        printf("- Feature %d\n", (features >> i) & 1);
    }
    
}   


int main()
{
    uint8_t options = 0; // Biến lưu trữ trạng thái các tính năng

    enableFeature(&options, GENDER | AGE | STATUS | ROLE); // Bật các tính năng

    // 0b0000 0001
    // 0b0000 0010
    // 0b0000 0100
    // 0b0000 0111 => sử dụng phep OR

    disableFeature(&options, GENDER | AGE | STATUS | ROLE); // Tắt các tính năng    

    listFeatures(options); // Liệt kê các tính năng hiện tại
    
    return 0;
}
