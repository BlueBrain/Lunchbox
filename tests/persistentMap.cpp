
/* Copyright (c) 2014 Stefan.Eilemann@epfl.ch
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 2.1 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <test.h>
#include <lunchbox/persistentMap.h>
#ifdef LUNCHBOX_USE_LEVELDB
#  include <leveldb/db.h>
#endif
#include <stdexcept>

using lunchbox::PersistentMap;

const int values[] = { 17, 53, 42, 65535, 32768 };
const size_t numValues = sizeof( values ) / sizeof( int );

template< class T > void insertVector( PersistentMap& map )
{
    std::vector< T > vector;
    for( size_t i = 0; i < numValues; ++i )
        vector.push_back( T( values[ i ] ));

    TEST( map.insert( typeid( vector ).name(), vector ));
}

template< class T > void readVector( PersistentMap& map )
{
    const std::vector< T >& vector =
        map.getVector< T >( typeid( vector ).name( ));
    TEST( vector.size() ==  numValues );
    for( size_t i = 0; i < numValues; ++i )
        TEST( vector[ i ] == T( values[i] ));
}

void setup( const std::string& uri )
{
    PersistentMap map( uri );
    TEST( map.insert( "foo", "bar" ));
    TEST( map[ "foo" ] == "bar" );
    TEST( map[ "bar" ].empty( ));

    insertVector< int >( map );
    insertVector< uint16_t >( map );
    readVector< int >( map );
    readVector< uint16_t >( map );

    std::set< int > set( values, values + numValues );
    TEST( map.insert( "std::set< int >", set ));
}

void read( const std::string& uri )
{
    PersistentMap map( uri );
    TEST( map[ "foo" ] == "bar" );
    TEST( map[ "bar" ].empty( ));

    readVector< int >( map );
    readVector< uint16_t >( map );

    const std::set< int >& set = map.getSet< int >( "std::set< int >" );
    TEST( set.size() ==  numValues );
    for( size_t i = 0; i < numValues; ++i )
        TEST( set.find( values[i] ) != set.end( ));
}

void testGenericFailures()
{
    try
    {
        setup( "foobar://" );
    }
    catch( const std::runtime_error& )
    {
        return;
    }
    TESTINFO( false, "Missing exception" );
}

void testLevelDBFailures()
{
#ifdef LUNCHBOX_USE_LEVELDB
    try
    {
        setup( "leveldb:///doesnotexist/deadbeef/coffee" );
    }
    catch( const leveldb::Status& status )
    {
        return;
    }
    TESTINFO( false, "Missing exception" );
#endif
}

int main( int, char** )
{
    try
    {
#ifdef LUNCHBOX_USE_LEVELDB
        setup( "" );
        setup( "leveldb://" );
        setup( "leveldb://persistentMap2.leveldb" );
        read( "" );
        read( "leveldb://" );
        read( "leveldb://persistentMap2.leveldb" );
#endif
    }
#ifdef LUNCHBOX_USE_LEVELDB
    catch( const leveldb::Status& status )
    {
        TESTINFO( !"exception", status.ToString( ));
    }
#endif
    catch( const std::runtime_error& error )
    {
        TESTINFO( !"exception", error.what( ));
    }

    testGenericFailures();
    testLevelDBFailures();

    return EXIT_SUCCESS;
}
