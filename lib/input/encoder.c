#include "input_drv.h"

#if USE_ENCODER

input_key_t encoder_keys[] = {
    {PIN_KEY_LEFT, LV_KEY_LEFT},
    {PIN_KEY_RIGHT, LV_KEY_RIGHT},
    {PIN_KEY_ENTER, LV_KEY_ENTER}};

void encoder_read(struct _lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

static lv_indev_drv_t lv_encoder_driver;
static lv_indev_t *lv_encoder_indev;

void encoder_register()
{
#if INPUT_DEBUG
    printf("encoder_register begin\n");
#endif
    input_key_init(encoder_keys, ARRAY_LEN(encoder_keys));
    lv_indev_drv_init(&lv_encoder_driver);
    lv_encoder_driver.type = LV_INDEV_TYPE_ENCODER;
    lv_encoder_driver.read_cb = encoder_read;
    lv_encoder_indev = lv_indev_drv_register(&lv_encoder_driver);
#if INPUT_DEBUG
    if (!lv_encoder_indev)
    {
        printf("lv_indev_drv_register failed\n");
    }
    printf("encoder_register done\n");
#endif
}

static lv_indev_state_t encoder_state = LV_INDEV_STATE_REL;
static int8_t enc_diff, left_pressed, right_pressed;

#define ENCODER_STEP 1

int encoder_scan()
{
    int keyCnt = 0;

    if (IS_KEY_PRESSED(PIN_KEY_ENTER))
    {
        encoder_state = LV_INDEV_STATE_PR;
        keyCnt++;
    }
    else
    {
        encoder_state = LV_INDEV_STATE_REL;
    }

    if (IS_KEY_PRESSED(PIN_KEY_LEFT))
    {
        left_pressed = 1;
        keyCnt++;
    }
    else
    {
        if (left_pressed)
        {
            left_pressed = 0;
            enc_diff = -1;
        }
    }

    if (IS_KEY_PRESSED(PIN_KEY_RIGHT))
    {
        right_pressed = 1;
        keyCnt++;
    }
    else
    {
        if (right_pressed)
        {
            right_pressed = 0;
            enc_diff = 1;
        }
    }
    return keyCnt;
}

void encoder_read(struct _lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    data->enc_diff = enc_diff;
    enc_diff = 0;
    data->state = encoder_state;
    // printf("encoder_read diff:%d, state: %d\n", data->enc_diff, data->state);
}

input_driver_t input_encoder = {
    .regist = encoder_register,
    .scan = encoder_scan};

#endif