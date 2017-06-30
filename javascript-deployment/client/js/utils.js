/*
 **  Usefuls functions
 */

function ScaleImage(image, new_width, new_height) {

    var img_width = image.width;
    var img_height = image.height;

    image.scale.setTo(new_width / img_width, new_height / img_height);

}

function deleteSprite(item) {
    item.remove(item.sprite);
    item.destroy();
    item = null;
}

function clearGroup(items) {
    items.removeChildren();
}