import express from "express"
import { Request, Response } from "express"

const App = express()
const port = 8080


App.get("/", function(req: Request, res: Response){
    res.send("Hello world!")
})


App.listen(port, function(){
    console.log("TS - Express Running")
})