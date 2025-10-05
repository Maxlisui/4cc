#ifndef _4CODER_MAXLISUI_CPP

#include "4coder_default_include.cpp"
#include "4coder_maxlisui_token.h"

function Lister_Result vim_run_lister(Application_Links *app, Lister *lister);
#define run_lister vim_run_lister

CUSTOM_ID(colors, defcolor_function);
CUSTOM_ID(colors, defcolor_type);
CUSTOM_ID(colors, defcolor_primitive);
CUSTOM_ID(colors, defcolor_macro);
CUSTOM_ID(colors, defcolor_enum);
CUSTOM_ID(colors, defcolor_global);
CUSTOM_ID(colors, defcolor_control);
CUSTOM_ID(colors, defcolor_struct);
CUSTOM_ID(colors, defcolor_non_text);

#include "4coder_vimrc.h"
#include "4coder_vim/4coder_vim_include.h"
#include "4coder_vim/4coder_vim_include.cpp"

#include "4coder_maxlisui_helper.h"

#include "4coder_maxlisui_token.cpp"

#include "4coder_maxlisui_build.cpp"
#include "4coder_maxlisui_colors.cpp"
#include "4coder_maxlisui_reformat.cpp"
#include "4coder_maxlisui_commands.cpp"

#include "4coder_maxlisui_draw.cpp"

#include "4coder_maxlisui_bindings.cpp"
#include "4coder_maxlisui_hooks.cpp"


#if !defined(META_PASS)
#include "generated/managed_id_metadata.cpp"
#endif

void
custom_layer_init(Application_Links *app){
  default_framework_init(app);
  set_all_default_hooks(app);

  vim_buffer_peek_list[ArrayCount(vim_default_peek_list) + 0] = MAXLISUI_peek_list[0];
  vim_buffer_peek_list[ArrayCount(vim_default_peek_list) + 1] = MAXLISUI_peek_list[1];
  vim_request_vtable[VIM_REQUEST_COUNT + MAXLISUI_REQUEST_Title]   = maxlisui_apply_title;
  vim_request_vtable[VIM_REQUEST_COUNT + MAXLISUI_REQUEST_Comment] = maxlisui_apply_comment;
  vim_request_vtable[VIM_REQUEST_COUNT + MAXLISUI_REQUEST_UnComment] = maxlisui_apply_uncomment;

  vim_text_object_vtable[VIM_TEXT_OBJECT_COUNT + MAXLISUI_OBJECT_param0] = {',', (Vim_Text_Object_Func *)maxlisui_object_param};
  vim_text_object_vtable[VIM_TEXT_OBJECT_COUNT + MAXLISUI_OBJECT_param1] = {';', (Vim_Text_Object_Func *)maxlisui_object_param};
  vim_text_object_vtable[VIM_TEXT_OBJECT_COUNT + MAXLISUI_OBJECT_camel0] = {'_', (Vim_Text_Object_Func *)maxlisui_object_camel};
  vim_text_object_vtable[VIM_TEXT_OBJECT_COUNT + MAXLISUI_OBJECT_camel1] = {'-', (Vim_Text_Object_Func *)maxlisui_object_camel};
  vim_init(app);

  set_custom_hook(app, HookID_SaveFile,                 maxlisui_file_save);
  set_custom_hook(app, HookID_BufferRegion,             maxlisui_buffer_region);
  set_custom_hook(app, HookID_RenderCaller,             maxlisui_render_caller);
  set_custom_hook(app, HookID_WholeScreenRenderCaller,  vim_draw_whole_screen);

  set_custom_hook(app, HookID_Tick,                     maxlisui_tick);
  set_custom_hook(app, HookID_NewFile,                  maxlisui_new_file);
  set_custom_hook(app, HookID_BeginBuffer,              maxlisui_begin_buffer);
  set_custom_hook(app, HookID_BufferEditRange,          vim_buffer_edit_range);
  set_custom_hook(app, HookID_ViewChangeBuffer,         vim_view_change_buffer);
  set_custom_hook(app, HookID_ViewEventHandler,         vim_view_input_handler);

  Thread_Context *tctx = get_thread_context(app);
  mapping_init(tctx, &framework_mapping);
  String_ID global_map_id = vars_save_string_lit("keys_global");
  String_ID file_map_id   = vars_save_string_lit("keys_file");
  String_ID code_map_id   = vars_save_string_lit("keys_code");
  maxlisui_essential_mapping(&framework_mapping, global_map_id, file_map_id, code_map_id);
  maxlisui_default_bindings(&framework_mapping, global_map_id, file_map_id, code_map_id);

  vim_default_bindings(app, KeyCode_BackwardSlash);
  maxlisui_vim_bindings(app);
}

#define _4CODER_MAXLISUI_CPP
#endif