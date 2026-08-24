/*********************************************************************************************************************
* STC32G144K Opensourec Library ����STC32G144K ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
* Copyright (c) 2025 SEEKFREE ��ɿƼ�
*
* ���ļ���STC32G144K��Դ���һ����
*
* STC32G144K ��Դ�� ���������
* �����Ը���������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù�������֤��������
* �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
*
* ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
* ����û�������������Ի��ʺ��ض���;�ı�֤
* ����ϸ����μ� GPL
*
* ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
* ���û�У������<https://www.gnu.org/licenses/>
*
* ����ע����
* ����Դ��ʹ�� GPL3.0 ��Դ����֤Э�� ������������Ϊ���İ汾
* ��������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
* ����֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
* ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
*
* �ļ�����          
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          MDK FOR C251
* ����ƽ̨          STC32G144K
* ��������          https://seekfree.taobao.com/
*
* �޸ļ�¼
* ����              ����           ��ע
* 2025-11-20        ��W            first version
********************************************************************************************************************/

#ifndef _zf_common_debug_h_
#define _zf_common_debug_h_

#include "zf_common_typedef.h"
#include "zf_common_fifo.h"

#define PRINTF_ENABLE               (1)                                             // ʹ��printf
#define USER_USB_CDC                (0)
#define PT_DEBUG_MODE               (1)
 

#define DEBUG_UART_DEFAULT_BAUDRATE  (115200)


#if (USER_USB_CDC == 0)
    #define DEBUG_UART_BAUDRATE   (DEBUG_UART_DEFAULT_BAUDRATE)

    #if (PT_DEBUG_MODE == 0)
        #define DEBUG_UART_INDEX  (UART_1)
        #define DEBUG_UART_TX_PIN (UART1_TX_P31)
        #define DEBUG_UART_RX_PIN (UART1_RX_P30)
    #elif (PT_DEBUG_MODE == 1)  
        #define DEBUG_UART_INDEX  (UART_7)
        #define DEBUG_UART_TX_PIN (UART7_TX_P51)
        #define DEBUG_UART_RX_PIN (UART7_RX_P50)
    #endif
#endif

#define DEBUG_UART_USE_INTERRUPT    (1)                                             // �Ƿ����� debug uart �����ж�

//-------------------------------------------------------------------------------------------------------------------
// �������     ����
// ����˵��     x           �ж��Ƿ񴥷����� 0-�������� 1-����������
// ���ز���     void
// ʹ��ʾ��     zf_assert(0);
// ��ע��Ϣ     һ�����ڲ����ж� zf_assert(0) �Ͷ��Ա���
//              Ĭ������»��� Debug UART ���
//              �����ʹ�ÿ�Դ������Ļ�ӿڳ�ʼ������Ļ �������Ļ����ʾ
//-------------------------------------------------------------------------------------------------------------------
#define zf_assert(x)                (debug_assert_handler((x), __FILE__, __LINE__))

uint32      debug_send_buffer(const uint8 *buff, uint32 len);

#if DEBUG_UART_USE_INTERRUPT                        // ������� debug uart �����ж�
    #define     DEBUG_RING_BUFFER_LEN   (128)        // ���廷�λ�������С Ĭ�� 128byte
#endif

extern fifo_struct  debug_uart_fifo;

uint32      debug_read_buffer(uint8 *buff, uint32 len);
void        debug_assert_handler        (uint8 pass, char *file, int line);
void        debug_init                  (void);

#endif