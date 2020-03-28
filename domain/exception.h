#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class Exception : std::exception
{
public:
    Exception(const std::string& message);
    virtual const char* what() const noexcept override;

private:
    std::string m_message;
};

#endif // EXCEPTION_H
