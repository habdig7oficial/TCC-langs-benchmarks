#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class Index: public drogon::HttpSimpleController<Index>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/",Get, Post);
    PATH_LIST_END
};
