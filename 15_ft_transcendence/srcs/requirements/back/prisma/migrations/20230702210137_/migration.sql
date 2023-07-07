/*
  Warnings:

  - You are about to drop the column `blockedUserId` on the `block` table. All the data in the column will be lost.
  - You are about to drop the column `blockerUserId` on the `block` table. All the data in the column will be lost.

*/
-- DropForeignKey
ALTER TABLE "block" DROP CONSTRAINT "block_blockedUserId_fkey";

-- DropForeignKey
ALTER TABLE "block" DROP CONSTRAINT "block_blockerUserId_fkey";

-- AlterTable
ALTER TABLE "block" DROP COLUMN "blockedUserId",
DROP COLUMN "blockerUserId";
