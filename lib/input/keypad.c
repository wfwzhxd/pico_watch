#include "input_drv.h"

input_key_t keypad_keys[] = {
    {PIN_KEY_A, 'A'},
    {PIN_KEY_B, 'B'}};

void keypad_read(struct _lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

static lv_indev_drv_t lv_keypad_driver;
static lv_indev_t *lv_keypad_indev;

void keypad_register()
{
#if INPUT_DEBUG
    printf("keypad_register begin\n");
#endif
    input_key_init(keypad_keys, ARRAY_LEN(keypad_keys));
    lv_indev_drv_init(&lv_keypad_driver);
    lv_keypad_driver.type = LV_INDEV_TYPE_KEYPAD;
    lv_keypad_driver.read_cb = keypad_read;
    lv_keypad_indev = lv_indev_drv_register(&lv_keypad_driver);
#if INPUT_DEBUG
    if (!lv_keypad_indev)
    {
        printf("lv_indev_drv_register failed\n");
    }
    printf("keypad_register done\n");
#endif
}

static lv_indev_state_t keypad_state = LV_INDEV_STATE_REL;
static lv_key_t key;

int keypad_scan()
{
    int keyCnt = 0;
    for (uint8_t i = 0; i < ARRAY_LEN(keypad_keys); i++)
    {
        if (IS_KEY_PRESSED(keypad_keys[i].gpio_num))
        {
            keypad_state = LV_INDEV_STATE_PR;
            key = keypad_keys[i].key_code;
            keyCnt++;
            return keyCnt;
        }
    }
    keypad_state = LV_INDEV_STATE_REL;
}

void keypad_read(struct _lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    data->key = key;
    data->state = keypad_state;
    // printf("keypad_read key:%d, state: %d\n", data->key, data->state);
}

input_driver_t input_keypad = {
    .regist = keypad_register,
    .scan = keypad_scan};