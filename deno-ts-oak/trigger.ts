import { Application, Router } from "https://deno.land/x/oak/mod.ts";

const App = new Application()
const port = 8080

const router = new Router();

router.get("/", function(ctx){
    ctx.response.body = "Hello world!"
})

App.use(router.routes())
App.use(router.allowedMethods())

App.addEventListener("listen", function(){
    console.log("TS - Deno Running")
})

await App.listen({
    port: port
})