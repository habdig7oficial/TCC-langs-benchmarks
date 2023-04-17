package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	App := gin.Default()
	App.GET("/", func(ctx *gin.Context) {
		ctx.String(http.StatusOK, "Hello world!")
	})
	App.Run()
}