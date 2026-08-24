
#include "hornshell.h"


// UART 输出辅助函数（替代 printf）
static char _pbuf[MAX_STR_LEN];

void _uart_print(const char* str) {
    uint16 len = 0;
    while (str[len] != '\0') len++;
    uart_write_buffer(DEBUG_UART_INDEX, (const uint8*)str, len);
}

// -------------------------- 全局函数映射表 --------------------------
// 基础函数名列表
static const char* base_func_name[] = {
    "test_func",
    "func_menu",
    "exit_shell",
    "mot_pwm",
    "mot_dir",
    "set_go_value",
    "write_eeprom",
    "init_eeprom",
    "value_list",
    "value_get",
    "value_set",
    "get_encoder",
    "get_adc",
    "force_read_eeprom",

    "pid_set",
    "pid_show",

    "float_value_list",
    "float_value_get",
    "float_value_set",

    "int16_value_list",
    "int16_value_get",
    "int16_value_set",

    "enc_dir_set",

    "fsm_set",
    "fsm_show",
    // 在此处添加更多函数名
};

// 基础函数指针列表（与base_func_name一一对应）
static BusinessFunc base_func_addr[] = {
    test_func,
    func_menu,
    exit_shell,
    mot_pwm,
    mot_dir,
    set_go_value,
    write_eeprom,
    init_eeprom_func,
    value_list_func,
    value_get,
    value_set,
    get_encoder,
    get_adc,
    force_read_eeprom_hs,

    pid_set_pt,
    pid_show_pt,

    float_value_list_func,
    float_value_get,
    float_value_set,

    int16_value_list_func,
    int16_value_get,
    int16_value_set,
    enc_dir_set,

    fsm_set,
    fsm_show,
    // 在此处添加更多函数指针
};

static int base_func_count = sizeof(base_func_name) / sizeof(base_func_name[0]);  // 已注册函数总数



static uint8* value_list[]={
    (uint8*)&GO_enable,
    (uint8*)&EEPROM_write_enable_value,

    (uint8*)&errorspeed_pid.temp_KP,
    (uint8*)&errorspeed_pid.temp_KI,
    (uint8*)&errorspeed_pid.temp_KD,
    (uint8*)&turn.temp_A,
    (uint8*)&turn.temp_B,
    (uint8*)&turn.temp_C,
    (uint8*)&temp_aim_speed,
    (uint8*)&round_pid.temp_KP,
    (uint8*)&round_pid.temp_KD,

    (errorspeed_pid_buff+0),
    (errorspeed_pid_buff+1),
    (errorspeed_pid_buff+2),
    (D_Sratio_turn_buff+0),
    (D_Sratio_turn_buff+1),
    (D_Sratio_turn_buff+2),
    (aim_speed_buff+0),
    (round_pid_buff+0),
    (round_pid_buff+1),
    (round_pid_buff+2),

    (uint8*)&monitor_func_index,

    
    // 在此处添加更多变量地址
};
static const char* value_name_list[] = {
    "GO_enable",
    "EEPROM_write_enable_value",

    "errorspeed_pid.temp_KP",
    "errorspeed_pid.temp_KI",
    "errorspeed_pid.temp_KD",
    "turn.temp_A",
    "turn.temp_B",
    "turn.temp_C",
    "temp_aim_speed",
    "round_pid.temp_KP",
    "round_pid.temp_KD",

    "errorspeed_pid_buff[0]",
    "errorspeed_pid_buff[1]",
    "errorspeed_pid_buff[2]",
    "D_Sratio_turn_buff[0]",
    "D_Sratio_turn_buff[1]",
    "D_Sratio_turn_buff[2]",
    "aim_speed_buff[0]",
    "round_pid_buff[0]",
    "round_pid_buff[1]",
    "round_pid_buff[2]",

    "monitor_func_index",

    "motor_left_PIDduty",
    "motor_right_PIDduty",
    "motor_top_PIDduty",


    // 在此处添加更多变量名
};
static int value_count = sizeof(value_name_list) / sizeof(value_name_list[0]);      // 已注册变量总数

static float* float_value_list[]={
    &aim_speed,

    &(turn.A),
    &(turn.B),
    &(turn.C),

    &(Lim_Turn),
    &md_turn_weight,
    &md_cross_min,
    &side_cross_min,
    &side_balance_max,
    &cross_error_scale,
    &round_confirm_ticks,
    &round_md_min,
    &round_md_max,
    &round_side_min,
    &round_side_max,
    &round_outer_diff_min,
    &round_side_diff_min,
    &round_inner_side_max,
    &round_side_ratio_min,
    &round_error_max,
    &round_out_yaw_min,
    &round_out_side_min,
    &round_out_angle,
    &round_out_done_yaw,

    &coe_pitch,
    &coe_yaw,

    &exp_acc,

    &PID_Steering_Kp_set,
    &exp_yaw_1,
    &exp_yaw_2,
};

static const char* float_value_name_list[]={
    "aim_speed",

    "turn.A",
    "turn.B",
    "turn.C",

    "Lim_Turn",
    "md_turn_weight",
    "md_cross_min",
    "side_cross_min",
    "side_balance_max",
    "cross_error_scale",
    "round_confirm_ticks",
    "round_md_min",
    "round_md_max",
    "round_side_min",
    "round_side_max",
    "round_outer_diff_min",
    "round_side_diff_min",
    "round_inner_side_max",
    "round_side_ratio_min",
    "round_error_max",
    "round_out_yaw_min",
    "round_out_side_min",
    "round_out_angle",
    "round_out_done_yaw",
    
    "coe_pitch",
    "coe_yaw",

    "exp_acc",

    "PID_Steering_Kp_set",
    "exp_yaw_1",
    "exp_yaw_2",
};
static int float_value_count = sizeof(float_value_name_list) / sizeof(float_value_name_list[0]);      // 已注册浮点变量总数

static int16* int16_value_list[]={
    &motor_left_PIDduty,
    &motor_right_PIDduty,
    &motor_top_PIDduty,

};

static const char* int16_value_name_list[]={
    "motor_left_PIDduty",
    "motor_right_PIDduty",
    "motor_top_PIDduty",
};
static int int16_value_count = sizeof(int16_value_name_list) / sizeof(int16_value_name_list[0]);      // 已注册浮点变量总数


// -------------------------- 测试用业务函数 --------------------------
char* test_func(char args[][MAX_STR_LEN], int args_len) {
    static char result[MAX_STR_LEN];
    char prefix[] = "test_func executed with: ";
    int res_idx = 0;
    int i;

    for (i = 0; i < MAX_STR_LEN; i++) result[i] = 0;
    for (i = 0; prefix[i] != '\0' && res_idx < MAX_STR_LEN - 1; i++) {
        result[res_idx++] = prefix[i];
    }
    if (args_len > 0 && args[0][0] != '\0') {
        for (i = 0; args[0][i] != '\0' && res_idx < MAX_STR_LEN - 1; i++) {
            result[res_idx++] = args[0][i];
        }
    }
    result[res_idx] = '\0';
    return result;
}

char* func_menu(char args[][MAX_STR_LEN], int args_len) {
    
    uint8 i;
    for(i=0; i<base_func_count; i++){
        sprintf(_pbuf, "func %d: %s\n", i, base_func_name[i]); _uart_print(_pbuf);
    }

    return horn_ok;
}

char* exit_shell(char args[][MAX_STR_LEN], int args_len) {
    // 这里可以添加一些退出前的清理工作
    fsm_state = 0; // 重置 FSM 状态
    return horn_ok;
}

char* mot_pwm(char args[][MAX_STR_LEN], int args_len) {
    uint8 channel;
    int16 duty;
    if (args_len < 2) {
        _uart_print("Usage: mot_pwm <channel> <duty>\n");
        return "ERR: insufficient args";
    }
    channel = (uint8)pt_atoi(args[0]);
    duty = (int16)pt_atoi(args[1]);
    if (channel >= PWM_CHANNEL_NUMBER) {
        _uart_print("ERR: invalid channel\n");
        return "ERR: invalid channel";
    }
    pwm_set_duty(pwm_channel_list[channel], duty);
    system_delay_ms(5);
    return horn_ok;
}

char* mot_dir(char args[][MAX_STR_LEN], int args_len) {
    uint8 channel;
    int16 direction;
    if (args_len < 2) {
        _uart_print("Usage: mot_dir <channel> <direction>\n");
        return "ERR: insufficient args";
    }
    channel = (uint8)pt_atoi(args[0]);
    direction = (int16)pt_atoi(args[1]);
    if (channel >= PWM_CHANNEL_NUMBER) {
        _uart_print("ERR: invalid channel\n");
        return "ERR: invalid channel";
    }
    gpio_set_level(mot_dir_pin_list[channel], direction); // 简单映射，实际使用中可能需要更复杂的逻辑
    return horn_ok;
}

char* set_go_value(char args[][MAX_STR_LEN], int args_len){
    uint8 value;

    motor_left_PIDduty = 0;
    motor_right_PIDduty = 0;

    value = (uint8)pt_atoi(args[0]);
    GO_enable=value;

    if(!GO_enable){
        motor_top_PIDduty=0;
    }

    return horn_ok;
}

char* write_eeprom(char args[][MAX_STR_LEN], int args_len){
    EEPROM_write_enable=1;
    eeprom_init();
    EEPROM_write_enable=0;
    return horn_ok;
}

char* init_eeprom_func(char args[][MAX_STR_LEN], int args_len){
    eeprom_init();
    return horn_ok;
}

char* value_list_func(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<value_count; i++){
        sprintf(_pbuf, "value %d: %s = %d\n", i, value_name_list[i], *value_list[i]); _uart_print(_pbuf);
    }
    return horn_ok;
}

char* value_get(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<value_count; i++){
        if(0 == str_compare(args[0], value_name_list[i])){
            sprintf(_pbuf, "%s = %d\n", value_name_list[i], *value_list[i]); _uart_print(_pbuf);
            return horn_ok;
        }
    }
    return "ERR: value not found";
}

char* value_set(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<value_count; i++){
        if(0 == str_compare(args[0], value_name_list[i])){
            *value_list[i] = (uint8)pt_atoi(args[1]);
            sprintf(_pbuf, "set %s = %d\n", value_name_list[i], *value_list[i]); _uart_print(_pbuf);
            return horn_ok;
        }
    }
    return "ERR: value not found";
}

char* get_adc(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<ADC_CHANNEL_NUMBER; i++){
        sprintf(_pbuf, "adc value %d =  %f\n", i, adc_data[i]); _uart_print(_pbuf);
    }
    return horn_ok;
}

char* get_encoder(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    
    sprintf(_pbuf, "encoder left value =  %d\n",count_left); _uart_print(_pbuf);
    sprintf(_pbuf, "encoder right value =  %d\n",count_right); _uart_print(_pbuf);
    return horn_ok;
}

char* force_read_eeprom_hs(char args[][MAX_STR_LEN], int args_len){
    force_read_eeprom();
    return horn_ok;
}

char* pid_set_pt(char args[][MAX_STR_LEN], int args_len) {
    uint8 pid_index;
    pid_index=pt_atoi(args[0]);
    //PID_struct_init(pid_list[pid_index], DELTA_PID, APP_MOTOR_MAX_PWM, 1000, pt_atof(args[1]), pt_atof(args[2]), pt_atof(args[3]));
    pid_list[pid_index]->p = (float)pt_atof(args[1]);
    pid_list[pid_index]->i = (float)pt_atof(args[2]);
    pid_list[pid_index]->d = (float)pt_atof(args[3]);
    
    Del_PID_Zero(pid_list[pid_index]);

    return horn_ok;
}

char* pid_show_pt(char args[][MAX_STR_LEN], int args_len) {
    uint8 pid_index;
    pid_index=pt_atoi(args[0]);
    sprintf(_pbuf, "p:%f i:%f d:%f mode:%d\n",pid_list[pid_index]->p,pid_list[pid_index]->i,
        pid_list[pid_index]->d,pid_list[pid_index]->pid_mode
    ); _uart_print(_pbuf);
    sprintf(_pbuf, "maxout:%d int_limit:%d \n",
        pid_list[pid_index]->MaxOutput,pid_list[pid_index]->IntegralLimit
    ); _uart_print(_pbuf);
    sprintf(_pbuf, "pos_out:%f last_pos_out:%f delta_u:%f delta_out:%f last_delta_out:%f\n"
        ,pid_list[pid_index]->pos_out,pid_list[pid_index]->last_pos_out,pid_list[pid_index]->delta_u,pid_list[pid_index]->delta_out,
        pid_list[pid_index]->last_delta_out); _uart_print(_pbuf);
    return horn_ok;
}

char* float_value_list_func(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<float_value_count; i++){
        sprintf(_pbuf, "value %d: %s = %f\n", i, float_value_name_list[i], *float_value_list[i]); _uart_print(_pbuf);
    }
    return horn_ok;
}

char* float_value_get(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<float_value_count; i++){
        if(0 == str_compare(args[0], float_value_name_list[i])){
            sprintf(_pbuf, "%s = %f\n", float_value_name_list[i], *float_value_list[i]); _uart_print(_pbuf);
            return horn_ok;
        }
    }
    return "ERR: value not found";
}

char* float_value_set(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<float_value_count; i++){
        if(0 == str_compare(args[0], float_value_name_list[i])){
            *float_value_list[i] = pt_atof(args[1]);
            sprintf(_pbuf, "set %s = %f\n", float_value_name_list[i], *float_value_list[i]); _uart_print(_pbuf);
            return horn_ok;
        }
    }
    return "ERR: value not found";
}

char* int16_value_list_func(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<int16_value_count; i++){
        sprintf(_pbuf, "value %d: %s = %d\n", i, int16_value_name_list[i], *int16_value_list[i]); _uart_print(_pbuf);
    }
    return horn_ok;
}

char* int16_value_get(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<int16_value_count; i++){
        if(0 == str_compare(args[0], int16_value_name_list[i])){
            sprintf(_pbuf, "%s = %d\n", int16_value_name_list[i], *int16_value_list[i]); _uart_print(_pbuf);
            return horn_ok;
        }
    }
    return "ERR: value not found";
}

char* int16_value_set(char args[][MAX_STR_LEN], int args_len){
    uint8 i;
    for(i=0; i<int16_value_count; i++){
        if(0 == str_compare(args[0], int16_value_name_list[i])){
            *int16_value_list[i] = (int16)pt_atoi16(args[1]);
            sprintf(_pbuf, "set %s = %d\n", int16_value_name_list[i], *int16_value_list[i]); _uart_print(_pbuf);
            return horn_ok;
        }
    }
    return "ERR: value not found";
}

char* enc_dir_set(char args[][MAX_STR_LEN], int args_len){
    dl=pt_atoi8(args[0]);
    dr=pt_atoi8(args[1]);
    return horn_ok;
}

char* fsm_set(char args[][MAX_STR_LEN], int args_len){
    fsm=pt_atoi8(args[0]);
    return horn_ok;
}

char* fsm_show(char args[][MAX_STR_LEN], int args_len){
    sprintf(_pbuf, "fsm state = %d\n", fsm); _uart_print(_pbuf);
    return horn_ok;
}


// -------------------------- 核心shell函数（C89+单片机适配） --------------------------
// 参数：cm_shell_str - 输入的命令字符串
// 参数：out_buf - 输出缓冲区（存储函数执行结果）
// 参数：buf_len - 输出缓冲区长度
// 返回值：0=成功，1=参数错误，2=函数未找到，3=执行异常
int shell(const char* cm_shell_str, char* out_buf, int buf_len) {
    char cm_shell_vec[MAX_SPLIT_COUNT][MAX_STR_LEN];
    int cm_shell_count = 0;
    int ret;
    char cm_funcname_vec[MAX_SPLIT_COUNT][MAX_STR_LEN];
    int cm_funcname_count = 0;
    char cm_para_vec[MAX_SPLIT_COUNT][MAX_STR_LEN];
    int cm_para_count = 0;
    int i, j;
    BusinessFunc back_addr;
    char* func_back;

    // 1. 入参合法性检查（单片机必须加，防止内存越界）
    if (cm_shell_str == 0 || out_buf == 0 || buf_len <= 0) {
        return 1;
    }
    // 初始化输出缓冲区
    out_buf[0] = '\0';

    // 2. 拆分完整命令字符串
    ret = horn_split_v2(cm_shell_str, cm_shell_vec, &cm_shell_count);
    if (ret != 0 || cm_shell_count == 0) {
        sprintf(_pbuf, "shell: split cm_shell_str failed, ret=%d\n", ret); _uart_print(_pbuf);
        return 1;
    }

    // 3. 拆分函数名
    ret = horn_split_v2(cm_shell_vec[0], cm_funcname_vec, &cm_funcname_count);
    if (ret != 0 || cm_funcname_count == 0) {
        sprintf(_pbuf, "shell: split funcname failed, ret=%d\n", ret); _uart_print(_pbuf);
        return 1;
    }

    // 4. 提取参数列表
    for (i = 1; i < cm_shell_count; i++) {
        j = 0;
        while (cm_shell_vec[i][j] != '\0' && j < MAX_STR_LEN - 1) {
            cm_para_vec[cm_para_count][j] = cm_shell_vec[i][j];
            j++;
        }
        cm_para_vec[cm_para_count][j] = '\0';
        cm_para_count++;
        sprintf(_pbuf, "vstr %s\n", cm_para_vec[cm_para_count - 1]); _uart_print(_pbuf);
    }

    // 5. 查找目标函数
    back_addr = horn_finder(cm_funcname_vec, cm_funcname_count);
    sprintf(_pbuf, "backaddr: %p\n", (void*)back_addr); _uart_print(_pbuf);

    // 6. 执行目标函数
    if (back_addr != 0) {
        sprintf(_pbuf, "exe func addr %p\n", (void*)back_addr); _uart_print(_pbuf);
        func_back = back_addr(cm_para_vec, cm_para_count);
        if (func_back != 0) {
            i = 0;
            while (func_back[i] != '\0' && i < buf_len - 1) {
                out_buf[i] = func_back[i];
                i++;
            }
            out_buf[i] = '\0';
            sprintf(_pbuf, "func message: %s\n", out_buf); _uart_print(_pbuf);
        } else {
            _uart_print("execute error\n");
            return 3;
        }
    } else {
        _uart_print("Failed execution\n");
        return 2;
    }

    return 0;
}

// -------------------------- 复用的工具函数实现（必须包含） --------------------------
// 1. 字符串拆分函数（完整实现）
int horn_split_v2(const char* cm_str, char out_str[MAX_SPLIT_COUNT][MAX_STR_LEN], int* out_count) {
    int flag = 0;
    int i;
    char temp[MAX_STR_LEN];
    int temp_idx;

    if (cm_str == 0 || out_str == 0 || out_count == 0) return 1;
    *out_count = 0;
    sprintf(_pbuf, "split v2:cm_str:%s\n", cm_str); _uart_print(_pbuf);

    while (cm_str[flag] != '\0' && *out_count < MAX_SPLIT_COUNT) {
        temp_idx = 0;
        for (i = 0; i < MAX_STR_LEN; i++) temp[i] = 0;

        while (cm_str[flag] != '\0') {
            if (HORN_EQ(cm_str[flag], '\n')) { flag++; break; }
            if (HORN_EQ(cm_str[flag], ' ')) { flag++; break; }
            
            if (HORN_EQ(cm_str[flag], '\"')) {
                flag++;
                while (cm_str[flag] != '\0' && !HORN_EQ(cm_str[flag], '\"') && temp_idx < MAX_STR_LEN - 1) {
                    temp[temp_idx++] = cm_str[flag++];
                }
                flag++;
                continue;
            }

            if (temp_idx < MAX_STR_LEN - 1) {
                temp[temp_idx++] = cm_str[flag++];
            } else {
                flag++;
            }
        }

        if (temp_idx > 0) {
            i = 0;
            while (temp[i] != '\0' && i < MAX_STR_LEN - 1) {
                out_str[*out_count][i] = temp[i];
                i++;
            }
            out_str[*out_count][i] = '\0';
            (*out_count)++;
        }

        if (*out_count >= MAX_SPLIT_COUNT) return 2;
    }
    return 0;
}

// 字符串trim函数（移除首尾空格）
void trim(char* s) {
    int start = 0;
    int end = 0;
    int i, j;

    if (s == 0 || s[0] == '\0') return;
    
    while (s[start] == ' ' || s[start] == '\t') {
        start++;
    }
    
    while (s[end] != '\0') {
        end++;
    }
    end--;
    while (end >= start && (s[end] == ' ' || s[end] == '\t')) {
        end--;
    }
    
    j = 0;
    for (i = start; i <= end && j < MAX_STR_LEN - 1; i++) {
        s[j++] = s[i];
    }
    s[j] = '\0';
}

// 字符串比较函数
int str_compare(const char* s1, const char* s2) {
    if (s1 == 0 || s2 == 0) return -1;
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) return (int)(*s1 - *s2);
        s1++;
        s2++;
    }
    return (int)(*s1 - *s2);
}

// 2. 函数查找器（根据C++版本适配）
BusinessFunc horn_finder(char func_name[][MAX_STR_LEN], int name_len) {
    BusinessFunc back_addr = 0;
    char check_func[MAX_STR_LEN];
    char find_func_name_temp[MAX_STR_LEN];
    int i, j;
    
    if (name_len == 0) return 0;
    
    for (i = 0; i < name_len; i++) {
        sprintf(_pbuf, "finder func input:%s.\n", func_name[i]); _uart_print(_pbuf);
    }
    
    for (i = 0; i < MAX_STR_LEN; i++) check_func[i] = 0;
    i = 0;
    while (func_name[0][i] != '\0' && i < MAX_STR_LEN - 1) {
        check_func[i] = func_name[0][i];
        i++;
    }
    check_func[i] = '\0';
    trim(check_func);
    
    sprintf(_pbuf, "finder: checking func name = %s\n", check_func); _uart_print(_pbuf);
    
    for (i = 0; i < base_func_count; i++) {
        for (j = 0; j < MAX_STR_LEN; j++) find_func_name_temp[j] = 0;
        j = 0;
        while (base_func_name[i][j] != '\0' && j < MAX_STR_LEN - 1) {
            find_func_name_temp[j] = base_func_name[i][j];
            j++;
        }
        find_func_name_temp[j] = '\0';
        
        sprintf(_pbuf, "finder checking func:%s\n", find_func_name_temp); _uart_print(_pbuf);
        
        if (0 == str_compare(check_func, find_func_name_temp)) {
            back_addr = base_func_addr[i];
            break;
        }
    }
    
    sprintf(_pbuf, "finder: backaddr %p\n", (void*)back_addr); _uart_print(_pbuf);
    return back_addr;
}



// -------------------------- UART Shell 接口 --------------------------
// FIFO 缓冲区
static fifo_struct  shell_uart_fifo= {0};
static uint8        shell_fifo_buffer[SHELL_FIFO_SIZE];
static uint8        shell_fifo_read_buf[SHELL_FIFO_SIZE];

// 命令行缓冲区
static char shell_rx_buf[MAX_STR_LEN];
static int  shell_rx_idx = 0;

// UART 接收中断回调（将数据写入 FIFO）
void shell_uart_rx_handler(uint8 dat) {
    uart_query_byte(DEBUG_UART_INDEX, &dat);
    fifo_write_buffer(&shell_uart_fifo, &dat, 1);
}

// 在主循环中调用，从 FIFO 读取数据并组装命令
// void shell_process(void) {
    
    
//     //gpio_set_level(IO_P52, 0);

//     char result_buf[MAX_STR_LEN];
//     uint32 fifo_data_count;
//     uint32 k;
//     int ret;
//     int i;

    

//     fifo_data_count = fifo_used(&shell_uart_fifo);
//     if (fifo_data_count == 0){
//         //_uart_print("shell_process: no data in fifo\n");
//         return;
//     }

//     interrupt_global_disable();
//     fifo_read_buffer(&shell_uart_fifo, shell_fifo_read_buf, &fifo_data_count, FIFO_READ_AND_CLEAN);
//     interrupt_global_enable();

//     /* 逐字节组装命令行 */
//     for (k = 0; k < fifo_data_count; k++) {
//         if (shell_fifo_read_buf[k] == '\n' || shell_fifo_read_buf[k] == '\r') {
//             if (shell_rx_idx > 0) {
//                 shell_rx_buf[shell_rx_idx] = '\0';

//                 /* 执行命令 */
//                 for (i = 0; i < MAX_STR_LEN; i++) result_buf[i] = 0;
//                 sprintf(_pbuf, "shell> %s\n", shell_rx_buf); _uart_print(_pbuf);
//                 ret = shell(shell_rx_buf, result_buf, MAX_STR_LEN);
//                 if (ret == 0) {
//                     sprintf(_pbuf, "OK: %s\n", result_buf); _uart_print(_pbuf);
//                 } else {
//                     sprintf(_pbuf, "ERR: ret=%d\n", ret); _uart_print(_pbuf);
//                 }

//                 /* 复位命令缓冲区 */
//                 shell_rx_idx = 0;
//                 for (i = 0; i < MAX_STR_LEN; i++) shell_rx_buf[i] = 0;
//             }
//         } else {
//             if (shell_rx_idx < MAX_STR_LEN - 1) {
//                 shell_rx_buf[shell_rx_idx++] = (char)shell_fifo_read_buf[k];
//             }
//         }
//     }

//     //gpio_set_level(IO_P52, 1);
    
// }

// 初始化 shell UART
void shell_uart_init(void) {
    int i;
    for (i = 0; i < MAX_STR_LEN; i++) shell_rx_buf[i] = 0;
    shell_rx_idx = 0;

    /* 初始化 FIFO */
    fifo_init(&shell_uart_fifo, FIFO_DATA_8BIT, shell_fifo_buffer, SHELL_FIFO_SIZE);


    
    /* 注册接收中断回调 */
    uart_rx_interrupt(DEBUG_UART_INDEX, ZF_ENABLE, shell_uart_rx_handler);
    interrupt_set_priority(UART1_DMA_IRQn, 3);

    _uart_print("Hornshell dev version period dc6smc\n");

}




