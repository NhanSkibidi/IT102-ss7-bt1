#include <stdio.h>
struct SmartDevice {
    int id;
    float voltage;
    float current;
    float power_watt;
    int is_active;
    int is_overloaded;
};
int main() {
    struct SmartDevice heater;
    heater.id = 101;
    heater.voltage = 220.0f;
    heater.current = 35.0f;
    heater.is_active = 1;
    heater.is_overloaded = 0;
    if (heater.is_active == 1) {
        if (heater.current > 30.0f) {
            heater.is_overloaded = 1;
            heater.is_active = 0;
            heater.power_watt = 0.0f;
        } else {
            heater.power_watt = heater.voltage * heater.current;
        }
    } else {
        heater.power_watt = 0.0f;
    }
    printf("=== HETHONG GIAM SAT THIET BI SMART HOME ===");
    printf("Ma thiet bi: %d\n", heater.id);
    printf("Trang thai hoat dong: %s\n",
           heater.is_active ? "BAT" : "TAT");
    printf("Cong suat tieu thu: %.2f W\n",
           heater.power_watt);
    printf("Canh bao qua tai (>30A): %s\n",
           heater.is_overloaded ? "CO (DA NGAT DIEN)" : "KHONG");
    return 0;
}
/*
```markdown
# Smart Home IoT - Quan ly thiet bi
## 1. Phan tich loi
Loi logic nam o viec chuong trinh tinh cong suat truoc khi kiem tra qua tai:
    heater.power_watt = heater.voltage * heater.current;
Voi dien ap 220V va dong dien 35A:
    220 * 35 = 7700 W
Sau do chuong trinh phat hien qua tai va thuc hien:
    heater.is_overloaded = 1;
    heater.is_active = 0;
Tuy nhien power_watt khong duoc cap nhat lai ve 0.0 W.
Do do xuat hien trang thai khong hop le:
    is_active = 0
    power_watt = 7700 W
Theo nghiep vu, khi thiet bi bi ngat dien thi cong suat phai bang 0.0 W.
## 2. Cach khac phuc
Khi phat hien dong dien vuot qua 30A:
    heater.is_overloaded = 1;
    heater.is_active = 0;
    heater.power_watt = 0.0f;
Neu dong dien khong vuot qua 30A va thiet bi dang bat:
    heater.power_watt = heater.voltage * heater.current;
## 3. Test Cases
| Truong hop | Du lieu dau vao | Ket qua sai thuc te | Ket qua dung mong doi |
|---|---|---|---|
| TC01 - Qua tai | 220V, 35A, is_active = 1 | TAT, 7700W | TAT, 0W, qua tai CO |
| TC02 - Hoat dong binh thuong | 220V, 10A, is_active = 1 | 2200W | BAT, 2200W, qua tai KHONG |
## 4. Ket luan
Nguyen nhan loi la cong suat duoc tinh truoc khi xu ly trang thai qua tai.
Sau khi sua, neu thiet bi bi qua tai va tu dong ngat dien thi power_watt duoc dat ve 0.0 W, dam bao trang thai thiet bi va chi so cong suat luon nhat quan.
*/