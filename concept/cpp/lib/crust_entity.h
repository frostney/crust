/*
    Crust Library - Cpp Concept Mockup -

    This Module defines a simple entity based on string properties and lambda functions

    2012, FreezDev
*/
#pragma once

/// \brief  STL Includes
#include <functional>
#include <vector>
#include <string>
#include <typeinfo>
#include <map>

/// \brief  Crust Library
namespace crust {

    /// \brief  Standard Base Class for Entities
    class Base {};

    /// \brief  Each entity has a parent type. This technique is called mixins and allows compile-time
    ///         object-extensions.
    template < class Mixin = Base > class Entity : public Mixin {
    public:
        /// \brief  Public Type Definitions
        typedef Mixin   Parent;
        typedef size_t  SizeType;

        /// \brief  Public Function Type Definition
        typedef void (*UpdateFunction) ( Entity<Mixin>*, float );
        typedef void (*RenderFunction) ( Entity<Mixin>* );
        typedef void (*InputFunction) ( Entity<Mixin>* );
        typedef void (*CloseFunction) ( Entity<Mixin>* );

        /// \brief  Untyped Entity Property
        struct UntypedProperty {
            std::string     ID;
            std::string     Value;
        };

        /// \brief  Property Collection
        struct Properties {

            /// \brief  Current Update Callback
            std::function< void ( Entity<Mixin>*, float ) >      UpdateFunc;
            bool                                                 ExclusiveUpdate;

            /// \brief  Current Render Callback
            std::function< void ( Entity<Mixin>* ) >             RenderFunc;
            bool                                                 ExclusiveRender;

            /// \brief  Current Render Callback
            std::function< void ( Entity<Mixin>* ) >             InputFunc;
            bool                                                 ExclusiveInput;

            /// \brief  Current Render Callback
            std::function< void ( Entity<Mixin>* ) >             CloseFunc;
            bool                                                 ExclusiveClose;

            /// \brief  Properties
            std::map< std::string, std::string >             EntityProperties;

        };

        /// \brief  Public Interface

        /// \brief  Sets the current update function
        void    setUpdate( std::function< void ( Entity<Mixin>*, float ) > func, bool exclusive = false );

        /// \brief  Sets the current render function
        void    setRender( std::function< void ( Entity<Mixin>* ) > func, bool exclusive = false );

        /// \brief  Sets the current render function
        void    setInput( std::function< void ( Entity<Mixin>* ) > func, bool exclusive = false );

        /// \brief  Sets the current render function
        void    setClose( std::function< void ( Entity<Mixin>* ) > func, bool exclusive = false );

        /// \brief  simple index operator
        std::string& operator [] ( std::string str );

        /// \brief  update callback
        void    onUpdate( float time );

        /// \brief  render callback
        void    onRender();

        /// \brief on input callback
        void    onInput();

        /// \brief  on close callback
        void    onClose();

    private:
        /// \brief  Private Data

        Properties m;

    };

    /// \brief  Implementation

    template < class Mixin >
    void    Entity< Mixin >::setUpdate(  std::function< void ( Entity<Mixin>*, float ) > func, bool exclusive ) {
        m.ExclusiveUpdate = exclusive;
        m.UpdateFunc      = func;
    }

    template < class Mixin >
    void    Entity< Mixin >::setRender( std::function< void ( Entity<Mixin>* ) > func, bool exclusive ) {
        m.ExclusiveRender = exclusive;
        m.RenderFunc      = func;
    }

    template < class Mixin >
    void    Entity< Mixin >::setInput( std::function< void ( Entity<Mixin>* ) > func, bool exclusive ) {
        m.ExclusiveInput  = exclusive;
        m.RenderFunc      = func;
    }

    template < class Mixin >
    void    Entity< Mixin >::setClose( std::function< void ( Entity<Mixin>* ) > func, bool exclusive ) {
        m.ExclusiveClose = exclusive;
        m.CloseFunc      = func;
    }

    template < class Mixin >
    std::string& Entity< Mixin >::operator [] ( std::string str ) {
        return m.EntityProperties[ str ];
    }

    template < class Mixin >
    void    Entity< Mixin >::onUpdate( float time ) {
        (m.UpdateFunc)(this,time);
    }

    template < class Mixin >
    void    Entity< Mixin >::onRender() {
        (m.RenderFunc)(this);
    }

    template < class Mixin >
    void    Entity< Mixin >::onInput() {
        (m.InputFunc)(this);
    }

    template < class Mixin >
    void    Entity< Mixin >::onClose() {
        (m.CloseFunc)(this);
    }



}
