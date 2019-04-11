//#ifndef MYPROPERTYHELPER_H
//#define MYPROPERTYHELPER_H

#pragma once
#include <QObject>


#define AUTO_PROPERTY(TYPE, NAME) \
    Q_PROPERTY(TYPE NAME READ NAME WRITE NAME NOTIFY NAME ## Changed ) \
    public: \
       TYPE NAME() const { return m_ ## NAME ; } \
       void NAME(TYPE value) { \
          if (m_ ## NAME == value)  return; \
          m_ ## NAME = value; \
          emit NAME ## Changed(value); \
        } \
       Q_SIGNAL void NAME ## Changed(TYPE value);\
    private: \
       TYPE m_ ## NAME;

#define READONLY_PROPERTY(TYPE, NAME) \
    Q_PROPERTY(TYPE NAME READ NAME CONSTANT ) \
    public: \
       TYPE NAME() const { return m_ ## NAME ; } \
    private: \
       void NAME(TYPE value) {m_ ## NAME = value; } \
       TYPE m_ ## NAME;



#define OUTPUT_GPIO_PROPERTY(NAME, wPInumberPIN) \
    Q_PROPERTY(bool NAME READ NAME WRITE NAME NOTIFY NAME ## Changed ) \
    public: \
       bool NAME() const { return m_ ## NAME ; } \
       void NAME(bool value) { \
          if (m_ ## NAME == value)  return; \
          m_ ## NAME = value; \
          emit NAME ## Changed(value); \
          if (value == true)  digitalWrite(wPInumberPIN, HIGH); \
          if (value == false)  digitalWrite(wPInumberPIN, LOW); \
        } \
       Q_SIGNAL void NAME ## Changed(bool value);\
    private: \
       int pin_ ## NAME = wPInumberPIN ; \
       bool m_ ## NAME;



#define INPUT_GPIO_PROPERTY(NAME, wPInumberPIN) \
    Q_PROPERTY(bool NAME READ NAME WRITE NAME NOTIFY NAME ## Changed ) \
    public: \
       bool NAME() const { return m_ ## NAME ; } \
       void NAME(bool value) { \
          if (m_ ## NAME == value)  return; \
          m_ ## NAME = value; \
          emit NAME ## Changed(value); \
        } \
       Q_SIGNAL void NAME ## Changed(bool value);\
    private: \
       int pin_ ## NAME = wPInumberPIN ; \
       bool m_ ## NAME;
//#endif // MYPROPERTYHELPER_H
