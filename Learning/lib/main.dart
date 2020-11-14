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
      theme: ThemeData(
        primarySwatch: Colors.teal,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: SafeArea(
        child: Scaffold(
          appBar: AppBar(
            title: Text("Afnan's Home Page"),
            centerTitle: true,
            leading: Icon(Icons.account_circle),
            actions: <Widget>[
              IconButton(icon: Icon(Icons.add_a_photo), onPressed: () {}),
            ],
          ),
          body: ListView(
            children: <Widget> [
              Column(
                children: [
                  SizedBox(height: 10,),
                  Container(
                    height: 300,
                    width: 250,
                    color: Colors.lightGreenAccent,
                    child: Center(
                      child: Text("Hello World", style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold),),
                    ),
                  ),
                  SizedBox(height: 10,),
                  Container(
                    height: 300,
                    width: 250,
                    color: Colors.lightGreenAccent,
                    child: Center(
                      child: Text("Hello World", style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold),),
                    ),
                  ),
                  SizedBox(height: 10,),
                  Container(
                    height: 300,
                    width: 250,
                    color: Colors.lightGreenAccent,
                    child: Center(
                      child: Text("Hello World", style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold),),
                    ),
                  ),
                ],
              ),
            ],
          ),
          backgroundColor: Colors.deepOrangeAccent,
        ),
      ),
    );
    throw UnimplementedError();
  }
}
