/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_libsbml_WRAP_H_
#define SWIG_libsbml_WRAP_H_

class SwigDirector_IdentifierTransformer : public IdentifierTransformer, public Swig::Director {

public:
    void swig_connect_director(JNIEnv *jenv, jobject jself, jclass jcls, bool swig_mem_own, bool weak_global);
    SwigDirector_IdentifierTransformer(JNIEnv *jenv);
    virtual ~SwigDirector_IdentifierTransformer();
    virtual int transform(SBase *element);
public:
    bool swig_overrides(int n) {
      return (n < 1 ? swig_override[n] : false);
    }
protected:
    bool swig_override[1];
};

class SwigDirector_ElementFilter : public ElementFilter, public Swig::Director {

public:
    void swig_connect_director(JNIEnv *jenv, jobject jself, jclass jcls, bool swig_mem_own, bool weak_global);
    SwigDirector_ElementFilter(JNIEnv *jenv);
    virtual ~SwigDirector_ElementFilter();
    virtual bool filter(SBase const *element);
public:
    bool swig_overrides(int n) {
      return (n < 1 ? swig_override[n] : false);
    }
protected:
    bool swig_override[1];
};

class SwigDirector_SBMLConverter : public SBMLConverter, public Swig::Director {

public:
    void swig_connect_director(JNIEnv *jenv, jobject jself, jclass jcls, bool swig_mem_own, bool weak_global);
    SwigDirector_SBMLConverter(JNIEnv *jenv);
    SwigDirector_SBMLConverter(JNIEnv *jenv, SBMLConverter const &c);
    virtual ~SwigDirector_SBMLConverter();
    virtual SBMLConverter *clone() const;
    virtual SBMLDocument *getDocument();
    virtual SBMLDocument const *getDocument() const;
    virtual ConversionProperties getDefaultProperties() const;
    virtual SBMLNamespaces *getTargetNamespaces();
    virtual bool matchesProperties(ConversionProperties const &props) const;
    virtual int setDocument(SBMLDocument const *doc);
    virtual int setProperties(ConversionProperties const *props);
    virtual ConversionProperties *getProperties() const;
    virtual int convert();
public:
    bool swig_overrides(int n) {
      return (n < 10 ? swig_override[n] : false);
    }
protected:
    bool swig_override[10];
};

class SwigDirector_SBMLValidator : public SBMLValidator, public Swig::Director {

public:
    void swig_connect_director(JNIEnv *jenv, jobject jself, jclass jcls, bool swig_mem_own, bool weak_global);
    SwigDirector_SBMLValidator(JNIEnv *jenv);
    SwigDirector_SBMLValidator(JNIEnv *jenv, SBMLValidator const &orig);
    virtual ~SwigDirector_SBMLValidator();
    virtual SBMLValidator *clone() const;
    virtual SBMLDocument *getDocument();
    virtual SBMLDocument const *getDocument() const;
    virtual int setDocument(SBMLDocument const *doc);
    virtual unsigned int validate();
    virtual void clearFailures();
public:
    bool swig_overrides(int n) {
      return (n < 6 ? swig_override[n] : false);
    }
protected:
    bool swig_override[6];
};


#endif
