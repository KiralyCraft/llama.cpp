// Chat conversion functions for server (Responses API, Anthropic API, OAI streaming diffs)

#pragma once

#include "chat.h"
#include "server-common.h"
#include "server-http.h"

#include "json.h"

inline constexpr char SERVER_RESPONSES_NAMESPACE_TOOL_MAP_KEY[] = "__responses_namespace_tool_map";

// Convert OpenAI Responses API format to OpenAI Chat Completions API format
json server_chat_convert_responses_to_chatcmpl(const json & body);

// Restore a Responses API namespace tool call after the chat parser returns its flattened name.
void server_chat_restore_responses_tool_namespace(json & tool_call, const json & namespace_tool_map);

// Convert Anthropic Messages API format to OpenAI Chat Completions API format
json server_chat_convert_anthropic_to_oai(const json & body);

// convert OpenAI transcriptions API format to OpenAI Chat Completions API format
json convert_transcriptions_to_chatcmpl(
    const json & body,
    const common_chat_templates * tmpls,
    const std::map<std::string, uploaded_file> & in_files,
    std::vector<raw_buffer> & out_files);

json server_chat_msg_diff_to_json_oaicompat(const common_chat_msg_diff & diff);
