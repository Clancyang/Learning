> ### 模式定义
> 运用共享技术有效地支持大量细粒度的对象

``` 
class Font {
private: 
    //unique object key
    string key; 
    //object state
    //.... 
public:
    Font(const string& key){
        //...
    }
}; 
```
```
class FontFactory{
private:
    map<string,Font* > fontPool; 
public:
    Font* GetFont(const string& key){ 
        map<string,Font*>::iterator item=fontPool.find(key);

        if(item != footPool.end()){   // 有就返回
            return fontPool[key];
        }
        else{                       
            Font* font = new Font(key);
            fontPool[key]= font;
            return font;
        } 
    } 
    void clear(){
        //...
    }
};
```
> ### 要点总结
* 面向对象很好地解决了抽象性的问题，但是作为一个运行在机器中的程序实体，我们需要考虑对象的代价问题。`Flyweight`主要解决面向对象的代价问题，一般不触及面向对像的抽象性问题。
* `Flyweight`采用对象共享的做法来降低系统中对象的个数，从而降低低细粒度对象给系统带来的内存压力。在具体实现方面，要注意对象状态的处理。
* 对象的数量太大从而导致对象内存开销加大——什么样的数量才算大？这需要我们仔细的根据具体应用情况进行评估，而不能凭空臆断。