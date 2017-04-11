//
//  EPSReactiveTableViewController.h
//  EPSReactiveTableVIewExample
//
//  Created by Peter Stuart on 2/21/14.
//  Copyright (c) 2014 Peter Stuart. All rights reserved.
//

@import UIKit;
@import ReactiveObjC;

#import "EPSReactiveList.h"



@interface EPSReactiveTableViewController : UITableViewController <EPSReactiveList>

/**
 The animation used when inserting rows.
 
 @note Set to `UITableViewRowAnimationAutomatic` by default.
 */
@property (nonatomic) UITableViewRowAnimation insertAnimation;

/**
 The animation used when deleting rows.
 
 @note Set to `UITableViewRowAnimationAutomatic` by default.
 */
@property (nonatomic) UITableViewRowAnimation deleteAnimation;

/**
 Override this method instead of `-tableView:cellForRowAtIndexPath`.
 @note Overriding this method is only necessary if you haven’t registered a cell class to use.
 @see -registerCellClass:forObjectsWithClass:
 @param object An object from the observed array.
 @param indexPath The index path corresponding to `object`.
 */
- (UITableViewCell *)tableView:(UITableView *)tableView cellForObject:(id)object atIndexPath:(NSIndexPath *)indexPath;

/**
 Override this method instead of `-tableView:didSelectRowAtIndexPath:`.
 @param object An object from the observed array.
 @param indexPath The index path corresponding to `object`.
 */
- (void)tableView:(UITableView *)tableView didSelectRowForObject:(id)object atIndexPath:(NSIndexPath *)indexPath;

/**
 Override this method instead of `-tableView:accessoryButtonTappedForRowWithIndexPath:`.
 @param object An object from the observed array.
 @param indexPath The index path corresponding to `object`.
 */
- (void)tableView:(UITableView *)tableView accessoryButtonTappedForObject:(id)object atIndexPath:(NSIndexPath *)indexPath;

#pragma mark - Commands

/**
 Set this property to the command that should execute when a row is deleted.
 The object for that row will be sent as input to the signal block.
 If editing is enabled for your table view, then the execution of this command
 MUST remove the object from your objects array (or signal of arrays).
*/
@property (readwrite, nonatomic, strong) RACCommand *deleteCommand;

#pragma mark - Signals

/**
 A signal which sends a `RACTuple` with the object corresponding to the selected row, the index path of the selected row, and the table view, whenever a row is selected.
 
 @code
 [self.didSelectRowSignal subscribeNext:^(RACTuple *tuple) {
 RACTupleUnpack(id object, NSIndexPath *indexPath, UITableView *tableView) = tuple;
 // Do something with `object`.
 }
 @endcode
 */
@property (readonly, nonatomic) RACSignal *didSelectRowSignal;

/**
 A signal which sends a `RACTuple` with the object corresponding to the row whose accessory was tapped, the index path of the row, and the table view, whenever an accessory is tapped.
 */
@property (readonly, nonatomic) RACSignal *accessoryButtonTappedSignal;

@end
