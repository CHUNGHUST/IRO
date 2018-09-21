/*
 *
 */
 
#ifndef _DATAPROCESS_H_
#define _DATAPROCESS_H_

#include "stm32f1xx_hal.h"

/*
 * @biref: luu vi tri dau '[' ',' ']' vd: [ABCD,a,a,a] ket qua tra ve la 0, 5,7,9,11
 * @param: *bufP: con tro tro den mang luu vi tri dau
 * @param: *src: con tro tro den mang dau vao
 * @retval: khong
 */
void luuViTri(uint8_t *bufP, char *src);

/*
 * @biref: tach 1 chuoi ra tu chuoi ban dau bat dau tai vi tri begin+1, do dai chuoi la length (tach ra chuoi moi o giua 2 dau lay ra duoc o ham luuVitri)
 * @param: *child: con tro tro den mang luu chuoi tach ra
 * @param: *parent: con tro tro den mang dau vao
 * @begin: vi tri bat dau
 * @retval: khong
 */
static void tachChuoi(char *child, char *parent, uint8_t begin, uint8_t length);

/*
 * @biref: tach 1 phan tu ra tu chuoi ban dau o vi tri index. parent = [ABC,DEF,GHJ], index = 1 => child = ABC, index = 3 => child = GHJ
 * @param: *child: con tro tro den mang luu chuoi tach ra
 * @param: *parent: con tro tro den mang dau vao
 * @param: *bufP: con tro tro den mang luu vi tri dau 
 * @param: chi so phan tu trong khoang giua 2 dau
 * @retval: khong
 * @NOTE: truoc khi goi ham nay bat buoc phai goi ham luuVitri truoc do
 */
static void tachPhantu(char *child, char *parent, uint8_t *bufP, uint8_t index);

/*
 * @biref: tach gia tri ra kieu int luu vao bValue
 * @param: *bValue: con tro tro den mang luu du lieu
 * @param: *src: con tro tro den mang dau vao
 * @param: *bufP: con tro tro den mang luu vi tri dau 
 * @param: index: chi so cua phan tu bat dau tach
 * @retval: khong
 */
void tachGiaTri(int16_t *bValue, char *src, uint8_t *bufP, uint8_t index);

///*
// * @biref: cai dat gia tri dien tro cua MCP41010 de mach IRO do duoc gia tri ADC gui ve
// * @param: *bValue: con tro tro toi mang gia tri ADC
// * @param: index: chi so cua phan tu trong mang bValue
// */
//void caiGiaTri(uint8_t channel, int16_t *bValue, uint8_t index);
#endif
