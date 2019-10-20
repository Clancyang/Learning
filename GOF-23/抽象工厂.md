> ### 模式定义
> 提供一个接口，让该接口负责创建一系列“相关或者相互依 赖的对象”，无需指定它们具体的类。
 

> 数据库访问有关的基类(纯虚类),**注：virtual ~className(){}略**


 ```
class IDBConnection{
    
};

class IDBCommand{
    
};

class IDataReader{
    
};
```

```
class IDBFactory{
public:
    virtual IDBConnection* CreateDBConnection()=0;
    virtual IDBCommand* CreateDBCommand()=0;
    virtual IDataReader* CreateDataReader()=0;
    
};
```

> SQL Server对应方法的具体实现
``` 
class SqlConnection: public IDBConnection{
    
};
class SqlCommand: public IDBCommand{
    
};
class SqlDataReader: public IDataReader{
    
};
```
> **SQL Server对应的抽象工厂**
```
class SqlDBFactory:public IDBFactory{
public:
    virtual IDBConnection* CreateDBConnection() {
        // ... 
    }
    virtual IDBCommand* CreateDBCommand() {
        // ... 
    }
    virtual IDataReader* CreateDataReader() {
        // ...
    } 
};
```
> Oracle对应方法的具体实现
``` 
class OracleConnection: public IDBConnection{
    
};
class OracleCommand: public IDBCommand{
    
};
class OracleDataReader: public IDataReader{
    
};
```
> **Oracle对应的抽象工厂**
```
class OracleDBFactory:public IDBFactory{
public:
    virtual IDBConnection* CreateDBConnection() {
        // ... 
    }
    virtual IDBCommand* CreateDBCommand() {
        // ... 
    }
    virtual IDataReader* CreateDataReader() {
        // ...
    }
 
};
```

```
class EmployeeDAO{
    IDBFactory* dbFactory; 
public:
    EmployeeDAO(IDBFactory* dbFactory){
        this->dbFactory = dbFactory;
    }
    vector<EmployeeDAO> GetEmployees(){
        IDBConnection* connection =
            dbFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command =
            dbFactory->CreateDBCommand();
        command->CommandText("...");
        command->SetConnection(connection); //关联性

        IDBDataReader* reader = command->ExecuteReader(); //关联性
        while (reader->Read()){

        } 
    }
};

 ```
 > ### 要点总结
 * 如果没有应对“多系列对象构建”的需求变化，则没有必要使用`Abstract Factory`模式，这时候使用简单的工厂完全可以。
* “系列对象”指的是在某一特定系列下的对象之间有相互依赖、 或作用的关系。不同系列的对象之间不能相互依赖。
* `Abstract Factory`模式主要在于应对“新系列”的需求变动。其缺点在于难以应对“新对象”的需求变动。
