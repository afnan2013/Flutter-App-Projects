import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: SafeArea(
        child: Scaffold(
          appBar: AppBar(
            title: Text("Home Page"),
            centerTitle: true,
            leading: Icon(Icons.account_circle),
            actions: <Widget>[
              IconButton(icon: Icon(Icons.add_a_photo), onPressed: () {}),
            ],
          ),
          body: Center(
              child: Text("Hello World", style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold),),
          ),
          backgroundColor: Colors.deepOrangeAccent,
        ),
      ),
    );
    throw UnimplementedError();
  }
}
