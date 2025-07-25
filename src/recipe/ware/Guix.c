/** ------------------------------------------------------------
 * SPDX-License-Identifier: GPL-3.0-or-later
 * -------------------------------------------------------------
 * File Authors  : Aoran Zeng <ccmywish@qq.com>
 * Contributors  :  Nil Null  <nil@null.org>
 * Created On    : <2023-09-11>
 * Last Modified : <2025-07-13>
 * ------------------------------------------------------------*/

/**
 * @update 2025-07-13
 *
 * @note 目前只有一个源, guixcn 的源不知道是否可用
 */
static Source_t wr_guix_sources[] =
{
  {&UpstreamProvider,  NULL, NULL},
  {&Sjtug_Zhiyuan,    "https://mirror.sjtu.edu.cn/git/guix.git", DelegateToMirror}
};
def_sources_n(wr_guix);


/**
 * @consult https://mirrors.sjtug.sjtu.edu.cn/docs/guix
 */
void
wr_guix_setsrc (char *option)
{
  chsrc_yield_source_and_confirm (wr_guix);

  char *file =  xy_strjoin (3, "(list (channel\n"
                               "       (inherit (car %default-channels))\n"
                               "       (url \"", source.url, "\")))");

  chsrc_note2 ("为防止扰乱配置文件，请手动写入以下内容到 ~/.config/guix/channels.scm 文件中");
  p(file);

  chsrc_determine_chgtype (ChgType_Manual);
  chsrc_conclude (&source);
}


Feature_t
wr_guix_feat (char *option)
{
  Feature_t f = {0};

  f.can_get = false;
  f.can_reset = false;

  f.can_english = false;
  f.can_user_define = false;

  return f;
}

def_target_sf(wr_guix);
