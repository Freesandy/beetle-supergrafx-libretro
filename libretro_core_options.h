#ifndef LIBRETRO_CORE_OPTIONS_H__
#define LIBRETRO_CORE_OPTIONS_H__

#include <stdlib.h>
#include <string.h>

#include <libretro.h>
#include <retro_inline.h>

#ifndef HAVE_NO_LANGEXTRA
#include "libretro_core_options_intl.h"
#endif

/*
 ********************************
 * VERSION: 1.3
 ********************************
 *
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_ENGLISH */

/* Default language:
 * - All other languages must include the same keys and values
 * - Will be used as a fallback in the event that frontend language
 *   is not available
 * - Will be used as a fallback for any missing entries in
 *   frontend language definition */

struct retro_core_option_definition option_defs_us[] = {
   {
      "sgx_palette",
     "调色板",
      "复合视频模式尝试重建原始硬件的输出色彩, 在某些游戏上可以显示更多的细节.",
      {
         { "RGB", NULL },
         { "Composite", "复合视频" },
         { NULL, NULL},
      },
      "RGB"
   },
   {
      "sgx_cdimagecache",
      "CD镜像缓存(需重启)",
      "读取CD镜像到内存, 首次载入需要较长时间.",
      {
         { "disabled",  "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "sgx_cdbios",
      "CD BIOS (需重启)",
      "大部分游戏可以在'System Card 3'下运行, 少数未授权游戏需要'Games Express'. ",
      {
         { "System Card 3", NULL },
         { "Games Express", NULL },
         { "System Card 1", NULL },
         { "System Card 2", NULL },
         { NULL, NULL },
      },
      "System Card 3"
   },
   {
      "sgx_detect_gexpress",
      "检测Games Express CD (需重启)",
      "启用后, 无论CD BIOS设置如何, 加载Games Express CD游戏都会自动加载Games Express CD卡BIOS.",
      {
         { "enabled",  "启用" },
         { "disabled",  "禁用" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "sgx_forcesgx",
      "强制SuperGrafx模拟(需重启)",
      "这对于运行Homebrew游戏或隔离无法在SuperGrafx模式下运行的游戏很有帮助. (如太空哈利) 即使存档与其他模式不兼容. 除非需要, 否则最好将此选项保留为默认(关闭). 无论使用哪种选项, 已知的Supergrafx游戏(例如Dai-Makaimura, Aldyns)都会自动切换到SuperGrafx.",
      {
         { "disabled",  "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "sgx_nospritelimit",
      "无活动块限制",
      "移除每扫描线16个活动块的硬件限制.",
      {
         { "disabled",  "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "sgx_ocmultiplier",
      "CPU超频倍率(需重启)",
      "较高的值可以减少游戏拖慢现象, 警告：可能导致错误或崩溃.",
      {
         { "1", NULL },
         { "2", NULL },
         { "3", NULL },
         { "4", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { "8", NULL },
         { "9", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { NULL, NULL },
      },
      "1"
   },
   {
      "sgx_hoverscan",
      "水平过扫描(仅352宽度模式)",
      "修改水平过扫描.",
      {
         { "300", NULL },
         { "302", NULL },
         { "304", NULL },
         { "306", NULL },
         { "308", NULL },
         { "310", NULL },
         { "312", NULL },
         { "314", NULL },
         { "316", NULL },
         { "318", NULL },
         { "320", NULL },
         { "322", NULL },
         { "324", NULL },
         { "326", NULL },
         { "328", NULL },
         { "330", NULL },
         { "332", NULL },
         { "334", NULL },
         { "336", NULL },
         { "338", NULL },
         { "340", NULL },
         { "342", NULL },
         { "344", NULL },
         { "346", NULL },
         { "348", NULL },
         { "350", NULL },
         { "352", NULL },
         { NULL, NULL },
      },
      "352"
   },
   {
      "sgx_initial_scanline",
      "初始扫描线",
      "第一条渲染的扫描的扫描线, 高于0的值会剪切屏幕顶部.",
      {
         { "0", NULL },
         { "1", NULL },
         { "2", NULL },
         { "3", NULL },
         { "4", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { "8", NULL },
         { "9", NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { "16", NULL },
         { "17", NULL },
         { "18", NULL },
         { "19", NULL },
         { "20", NULL },
         { "21", NULL },
         { "22", NULL },
         { "23", NULL },
         { "24", NULL },
         { "25", NULL },
         { "26", NULL },
         { "27", NULL },
         { "28", NULL },
         { "29", NULL },
         { "30", NULL },
         { "31", NULL },
         { "32", NULL },
         { "33", NULL },
         { "34", NULL },
         { "35", NULL },
         { "36", NULL },
         { "37", NULL },
         { "38", NULL },
         { "39", NULL },
         { "40", NULL },
         { NULL, NULL },
      },
      "3"
   },
   {
      "sgx_last_scanline",
      "最后一条扫描线",
      "最后一条渲染的扫描线, 低于242的值会剪切屏幕底部.",
      {
         { "208", NULL },
         { "209", NULL },
         { "210", NULL },
         { "211", NULL },
         { "212", NULL },
         { "213", NULL },
         { "214", NULL },
         { "215", NULL },
         { "216", NULL },
         { "217", NULL },
         { "218", NULL },
         { "219", NULL },
         { "220", NULL },
         { "221", NULL },
         { "222", NULL },
         { "223", NULL },
         { "224", NULL },
         { "225", NULL },
         { "226", NULL },
         { "227", NULL },
         { "228", NULL },
         { "229", NULL },
         { "230", NULL },
         { "231", NULL },
         { "232", NULL },
         { "233", NULL },
         { "234", NULL },
         { "235", NULL },
         { "236", NULL },
         { "237", NULL },
         { "238", NULL },
         { "239", NULL },
         { "240", NULL },
         { "241", NULL },
         { "242", NULL },
         { NULL, NULL },
      },
      "242"
   },
   {
      "sgx_cddavolume",
      "(CD) CDDA音量%",
      "只应用于CD游戏, 音量值设置过高可能会导致音频削峰.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "90", NULL },
         { "100", NULL },
         { "110", NULL },
         { "120", NULL },
         { "130", NULL },
         { "140", NULL },
         { "150", NULL },
         { "160", NULL },
         { "170", NULL },
         { "180", NULL },
         { "190", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "sgx_adpcmvolume",
       "(CD) ADPCM音量%",
      "只应用于CD游戏, 音量值设置过高可能会导致音频削峰.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "90", NULL },
         { "100", NULL },
         { "110", NULL },
         { "120", NULL },
         { "130", NULL },
         { "140", NULL },
         { "150", NULL },
         { "160", NULL },
         { "170", NULL },
         { "180", NULL },
         { "190", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "sgx_cdpsgvolume",
      "(CD) PSG音量%",
      "只应用于CD游戏, 音量值设置过高可能会导致音频削峰.",
      {
         { "0", NULL },
         { "10", NULL },
         { "20", NULL },
         { "30", NULL },
         { "40", NULL },
         { "50", NULL },
         { "60", NULL },
         { "70", NULL },
         { "80", NULL },
         { "90", NULL },
         { "100", NULL },
         { "110", NULL },
         { "120", NULL },
         { "130", NULL },
         { "140", NULL },
         { "150", NULL },
         { "160", NULL },
         { "170", NULL },
         { "180", NULL },
         { "190", NULL },
         { "200", NULL },
         { NULL, NULL },
      },
      "100"
   },
   {
      "sgx_cdspeed",
      "(CD) CD 读速",
      "配置更快的载入速度,但是可能会使一些游戏产生问题.",
      {
         { "1", NULL },
         { "2", NULL },
         { "4", NULL },
         { "8", NULL },
         { NULL, NULL },
      },
      "1"
   },
   {
      "sgx_multitap",
      "分插",
      "最多启用5人分插, 建议不要修改, 仅在某些情况下需要禁用它(超兄贵).",
      {
         { "enabled",  "启用" },
         { "disabled",  "禁用" },
         { NULL, NULL},
      },
      "enabled"
   },
   {
      "sgx_turbo_delay",
      "连发延迟",
      "数字越大, 连发越慢.",
      {
         { "3", NULL },
         { "4", NULL },
         { "5", NULL },
         { "6", NULL },
         { "7", NULL },
         { "8", NULL },
         { "9", NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { "30", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "3"
   },
   {
      "sgx_turbo_toggle",
      "连发热键模式",
      "将连发快捷键变成On/Off开关或专用连发键. 禁用时,所有连发功能都将禁用. (默认热键是X/Y按钮).",
      {
         { "disabled",  "禁用" },
         { "switch", "On/Off开关" },
         { "dedicated", "专用连发键" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "sgx_turbo_toggle_hotkey",
      "备用连发热键",
      "启用后分配一个不同的连发快捷键(默认X/Y或L3/R3). 仅在选项'连发热键模式'处于'On/Off开关'模式时有效. 此切换到6键游戏手柄模式时，可避免重新映射Button III和IV.",
      {
         { "disabled", "X/Y" },
         { "enabled", "L3/R3" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "sgx_disable_softreset",
      "禁用软重置(RUN + SELECT)",
      "在PCE游戏手柄上同时按RUN和SELECT将进行软复位. 这是默认的硬件功能. 如果要关闭软重置功能, 请将其设置为启用.",
      {
         { "disabled",  "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "sgx_up_down_allowed",
      "允许反方向同时按下",
      "启用此功能将允许同时按下/快速交替/同时按住左右两个方向 (在某些游戏中为上下). 这可能导致在某些游戏中发生基于运动的错误. 最好禁用此核心选项. ",
      {
         { "disabled",  "禁用" },
         { "enabled",  "启用" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "sgx_mouse_sensitivity",
      "鼠标灵敏度",
      "配置PCE鼠标设备类型的敏感度.",
      {
         { "0.25", NULL },
         { "0.50", NULL },
         { "0.75", NULL },
         { "1.00", NULL },
         { "1.25", NULL },
         { "1.50", NULL },
         { "1.75", NULL },
         { "2.00", NULL },
         { "2.25", NULL },
         { "2.50", NULL },
         { "2.75", NULL },
         { "3.00", NULL },
         { "3.25", NULL },
         { "3.50", NULL },
         { "3.75", NULL },
         { "4.00", NULL },
         { "4.25", NULL },
         { "4.50", NULL },
         { "4.75", NULL },
         { "5.00", NULL },
         { NULL, NULL },
      },
      "1.25"
   },
   {
      "sgx_aspect_ratio",
      "长宽比",
      "选择自动(PAR)宽高比, 6:5(默认设置)或4:3 TV宽高比. 当使用经常在256和352模式之间切换的游戏并使用自动宽高比时, 最好将'水平宽度'设置为342, 以最大程度地减少调整大小和多余的黑线, 因为此宽度是256宽度模式的比率.",
      {
         { "auto", "自动" },
         { "6:5", NULL },
         { "4:3", NULL },
         { NULL, NULL },
      },
      "auto"
   },
   { NULL, NULL, NULL, {{0}}, NULL },
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

#ifndef HAVE_NO_LANGEXTRA
struct retro_core_option_definition *option_defs_intl[RETRO_LANGUAGE_LAST] = {
   option_defs_us, /* RETRO_LANGUAGE_ENGLISH */
   NULL,           /* RETRO_LANGUAGE_JAPANESE */
   NULL,           /* RETRO_LANGUAGE_FRENCH */
   NULL,           /* RETRO_LANGUAGE_SPANISH */
   NULL,           /* RETRO_LANGUAGE_GERMAN */
   NULL,           /* RETRO_LANGUAGE_ITALIAN */
   NULL,           /* RETRO_LANGUAGE_DUTCH */
   NULL,           /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   NULL,           /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   NULL,           /* RETRO_LANGUAGE_RUSSIAN */
   NULL,           /* RETRO_LANGUAGE_KOREAN */
   NULL,           /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   NULL,           /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   NULL,           /* RETRO_LANGUAGE_ESPERANTO */
   NULL,           /* RETRO_LANGUAGE_POLISH */
   NULL,           /* RETRO_LANGUAGE_VIETNAMESE */
   NULL,           /* RETRO_LANGUAGE_ARABIC */
   NULL,           /* RETRO_LANGUAGE_GREEK */
   option_defs_tr, /* RETRO_LANGUAGE_TURKISH */
};
#endif

/*
 ********************************
 * Functions
 ********************************
*/

/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

static INLINE void libretro_set_core_options(retro_environment_t environ_cb)
{
   unsigned version = 0;

   if (!environ_cb)
      return;

   if (environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version) && (version >= 1))
   {
#ifndef HAVE_NO_LANGEXTRA
      struct retro_core_options_intl core_options_intl;
      unsigned language = 0;

      core_options_intl.us    = option_defs_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
          (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = option_defs_intl[language];

      environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_intl);
#else
      environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS, &option_defs_us);
#endif
   }
   else
   {
      size_t i;
      size_t num_options               = 0;
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      /* Allocate arrays */
      variables  = (struct retro_variable *)calloc(num_options + 1, sizeof(struct retro_variable));
      values_buf = (char **)calloc(num_options, sizeof(char *));

      if (!variables || !values_buf)
         goto error;

      /* Copy parameters from option_defs_us array */
      for (i = 0; i < num_options; i++)
      {
         const char *key                        = option_defs_us[i].key;
         const char *desc                       = option_defs_us[i].desc;
         const char *default_value              = option_defs_us[i].default_value;
         struct retro_core_option_value *values = option_defs_us[i].values;
         size_t buf_len                         = 3;
         size_t default_index                   = 0;

         values_buf[i] = NULL;

         if (desc)
         {
            size_t num_values = 0;

            /* Determine number of values */
            while (true)
            {
               if (values[num_values].value)
               {
                  /* Check if this is the default value */
                  if (default_value)
                     if (strcmp(values[num_values].value, default_value) == 0)
                        default_index = num_values;

                  buf_len += strlen(values[num_values].value);
                  num_values++;
               }
               else
                  break;
            }

            /* Build values string */
            if (num_values > 0)
            {
               size_t j;

               buf_len += num_values - 1;
               buf_len += strlen(desc);

               values_buf[i] = (char *)calloc(buf_len, sizeof(char));
               if (!values_buf[i])
                  goto error;

               strcpy(values_buf[i], desc);
               strcat(values_buf[i], "; ");

               /* Default value goes first */
               strcat(values_buf[i], values[default_index].value);

               /* Add remaining values */
               for (j = 0; j < num_values; j++)
               {
                  if (j != default_index)
                  {
                     strcat(values_buf[i], "|");
                     strcat(values_buf[i], values[j].value);
                  }
               }
            }
         }

         variables[i].key   = key;
         variables[i].value = values_buf[i];
      }

      /* Set variables */
      environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);

error:

      /* Clean up */
      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}

#ifdef __cplusplus
}
#endif

#endif