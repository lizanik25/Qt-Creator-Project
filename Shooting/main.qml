import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.15
import QtPositioning 5.15

Window {
    visible: true
    width: 640
    height: 480
    title: "US Map"

    Plugin {
            id: mapPlugin
            name: "osm"  // Using OpenStreetMap as the provider
        }


    Map {
            id: map
            anchors.fill: parent
            plugin: mapPlugin
            center: QtPositioning.coordinate(37.7749, -122.4194)  // Coordinates for San Francisco
            zoomLevel: 14

            MapItemView {
                model: positionModel
                delegate: MapQuickItem {
                    coordinate: QtPositioning.coordinate(model.latitude, model.longitude)
                    anchorPoint.x: sourceItem.width / 2
                    anchorPoint.y: sourceItem.height

                    sourceItem: Image {
                        id: image
                        source: "persian-red-map-marker-2-icon-google-map-marker-gif-heart-alphabet-text-path-transparent-png-2746621.png"  // Your custom marker image
                    }
                }
            }
        }

        ListModel {
            id: positionModel
            // Example coordinates
            ListElement { latitude: 37.7749; longitude: -122.4194 }  // San Francisco
            ListElement { latitude: 34.0522; longitude: -118.2437 }  // Los Angeles
            ListElement { latitude: 40.7128; longitude: -74.0060 }   // New York City
        }
    }
